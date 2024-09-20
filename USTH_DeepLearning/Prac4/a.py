import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler

salary = [10, 5, 6, 7, 8, 9, 4, 5, 8, 4, 8, 7, 4, 5, 4, 5, 6, 7, 8]
working_time = [1, 1, 1.8, 1, 2, 0.5, 3, 2.5, 1, 1, 0.1, 0.15, 1, 0.8, 0.3, 1, 0.5, 0.3, 0.2, 0.15]
loan_decision = [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

X = np.array(list(zip(salary, working_time)))
y = np.array(loan_decision)

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

model = LogisticRegression()
model.fit(X_scaled, y)

plt.figure(figsize = (10, 6))
plt.scatter(X_scaled[y == 0, 0], X_scaled[y == 0, 1], c = "red", label = "Rejected")
plt.scatter(X_scaled[y == 1, 0], X_scaled[y == 1, 1], c = "blue", label = "Approved")

w = model.coef_[0]
b = model.intercept_[0]
x_boundary = np.array([X_scaled[:, 0].min(), X_scaled[:, 0].max()])
y_boundary = -(w[0] * x_boundary + b) / w[1]

plt.plot(x_boundary, y_boundary, c = "red", linewidth=2, label="Decision Boundary")

plt.xlabel("Scaled Salary")
plt.ylabel("Scaled Working Time")
plt.title("Loan Decision Analysis")
plt.show()
