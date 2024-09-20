import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import precision_score, recall_score, f1_score, accuracy_score, confusion_matrix, ConfusionMatrixDisplay

# Random Forest 
# Data Import
X_train_rf = pd.read_csv("train_X.csv").drop("Id", axis = 1).values
Y_train_rf = pd.read_csv("train_Y.csv").drop("Id", axis = 1).values.ravel()
X_test_rf = pd.read_csv("test_X.csv").drop("Id", axis = 1).values
Y_test_rf = pd.read_csv("test_Y.csv").drop("Id", axis = 1).values.ravel()

# Random Forest Model
rf_model = RandomForestClassifier(n_estimators = 100, random_state = 42)
rf_model.fit(X_train_rf, Y_train_rf)
Y_pred_rf = rf_model.predict(X_test_rf)

# Feature Importance Plot
feature_names = ["Pclass", "Sex", "Age", "SibSp", "Parch", "Fare", "Embarked"]
importances = rf_model.feature_importances_
indices = np.argsort(importances)[::-1]

plt.figure(figsize=(10, 5))
plt.title("Feature Importances")
plt.bar(range(X_train_rf.shape[1]), importances[indices], align="center")
plt.xticks(range(X_train_rf.shape[1]), [feature_names[i] for i in indices], rotation='horizontal')
plt.show()

# Logistic Regression 
# Data Import
X_train_lr = pd.read_csv("train_X.csv").drop("Id", axis = 1).values.T
Y_train_lr = pd.read_csv("train_Y.csv").drop("Id", axis = 1).values.reshape(1, -1)
X_test_lr = pd.read_csv("test_X.csv").drop("Id", axis = 1).values.T
Y_test_lr = pd.read_csv("test_Y.csv").drop("Id", axis = 1).values.reshape(1, -1)

# Scatter Plots
def scatter_plot_data(X, Y, title, subplot_index, xlabel = "Index", ylabel = "Feature Values", labels = None):
    plt.subplot(2, 2, subplot_index)
    for i in range(X.shape[0]):
        plt.scatter(np.arange(X.shape[1]), X[i, :], label = labels[i] if labels else f"Feature {i+1}")
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.legend()

plt.figure(figsize=(20, 10))
scatter_plot_data(X_train_lr, Y_train_lr, "Scatter plot of X_train features", 1, labels = feature_names)
scatter_plot_data(Y_train_lr, Y_train_lr, "Scatter plot of Y_train", 2, ylabel = "Y_train")
scatter_plot_data(X_test_lr, Y_test_lr, "Scatter plot of X_test features", 3, labels = feature_names)
scatter_plot_data(Y_test_lr, Y_test_lr, "Scatter plot of Y_test", 4, ylabel = "Y_test")
plt.tight_layout()
plt.show()

# Logistic Regression Model
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

print("---")
def model_lr(X, Y, learning_rate, iterations):
    m, n = X.shape[1], X.shape[0]
    W, B = np.zeros((n, 1)), 0
    cost_list = []
    for i in range(iterations):
        Z = np.dot(W.T, X) + B
        A = sigmoid(Z)
        # Cost Function
        cost = -(1/m) * np.sum(Y * np.log(A) + (1 - Y) * np.log(1 - A))
        # Gradient Descent 
        W -= learning_rate * (1/m) * np.dot(A - Y, X.T).T
        B -= learning_rate * (1/m) * np.sum(A - Y)
        # Tracking cost value over iterations
        if i % (iterations // 10) == 0:
            print(f"Cost after {i} iterations: {cost}")
        cost_list.append(cost)

    return W, B, cost_list

W_lr, B_lr, cost_list_lr = model_lr(X_train_lr, Y_train_lr, 0.001, 100000)

# Plot cost function
plt.plot(np.arange(100000), cost_list_lr)
plt.title("Cost Function Over Iterations")
plt.xlabel("Iterations")
plt.ylabel("Cost")
plt.show()

# Predictions
def predict_lr(W, B, X):
    Z = np.dot(W.T, X) + B
    A = sigmoid(Z)
    return (A > 0.5).astype(int)
predictions_lr = predict_lr(W_lr, B_lr, X_test_lr)

# Visualize the True vs Predicted Labels for Each Model
plt.figure(figsize = (10, 5))
plt.hist([Y_test_rf, Y_pred_rf, Y_test_lr.flatten(), predictions_lr.flatten()],
         bins = np.arange(-0.5, 2, 1),
         label = ["True Labels (RF)", "Predicted Labels (RF)", "True Labels (LR)", "Predicted Labels (LR)"],
         alpha = 0.7, color=["blue", "orange", "green", "red"])
plt.xticks([0, 1])
plt.xlabel("Label")
plt.ylabel("Frequency")
plt.title("Histogram of True vs Predicted Labels")
plt.legend(loc = "upper right")
plt.show()

# Evaluation Metrics
cm_rf = confusion_matrix(Y_test_rf, Y_pred_rf)
cm_lr = confusion_matrix(Y_test_lr.flatten(), predictions_lr.flatten())

fig, ax = plt.subplots(1, 2, figsize = (12, 5))
ConfusionMatrixDisplay(cm_rf, display_labels = [0, 1]).plot(ax = ax[0])
ax[0].set_title("Random Forest Confusion Matrix")
ConfusionMatrixDisplay(cm_lr, display_labels = [0, 1]).plot(ax = ax[1])
ax[1].set_title("Logistic Regression Confusion Matrix")
plt.show()

def specificity(cm):
    tn, fp, fn, tp = cm.ravel()
    return (tn / (tn + fp)) * 100

def accuracy_lr(X, Y, W, B):
    predictions = predict_lr(W, B, X)
    return np.mean(predictions == Y) * 100

# Random Forest Metrics
precision_rf = precision_score(Y_test_rf, Y_pred_rf) * 100
recall_rf = recall_score(Y_test_rf, Y_pred_rf) * 100
f1_rf = f1_score(Y_test_rf, Y_pred_rf) * 100
specificity_rf = specificity(cm_rf)
accuracy_rf = accuracy_score(Y_test_rf, Y_pred_rf) * 100


# Logistic Regression Metrics
precision_lr = precision_score(Y_test_lr.flatten(), predictions_lr.flatten()) * 100
recall_lr = recall_score(Y_test_lr.flatten(), predictions_lr.flatten()) * 100
f1_lr = f1_score(Y_test_lr.flatten(), predictions_lr.flatten()) * 100
specificity_lr = specificity(cm_lr)
accuracy_lr = accuracy_lr(X_test_lr, Y_test_lr.flatten(), W_lr, B_lr)

# Print Metrics
print("---")
print(f"""Random Forest Metrics: 
      - Precision: {precision_rf:.2f}% 
      - Recall: {recall_rf:.2f}%  
      - F-Score: {f1_rf:.2f}% 
      - Specificity: {specificity_rf:.2f}% 
      - Accuracy: {accuracy_rf:.2f}%""")
print("---")
print(f"""Logistic Regression Metrics: 
      - Precision: {precision_lr:.2f}% 
      - Recall: {recall_lr:.2f}% 
      - F-Score: {f1_lr:.2f}% 
      - Specificity: {specificity_lr:.2f}% 
      - Accuracy: {accuracy_lr:.2f}%""")


