import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
import pandas as pd

# Load the data (replace 'data.xlsx' with your actual path)
data = pd.read_excel('data.xlsx')

# Separate features (dBm values) and target variables (x, y coordinates)
X = data[['router_dbm_1', 'router_dbm_2', 'router_dbm_3', 'router_dbm_4']]
y = data[['x', 'y']]

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Standardize the dBm values for better training performance
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Define the model
model = Sequential([
    Dense(64, activation='relu', input_shape=(4,)),  # Input layer (4 neurons) + first hidden layer
    Dense(32, activation='relu'),                    # Second hidden layer
    Dense(2)                                         # Output layer (2 neurons for x and y)
])

# Compile the model
model.compile(optimizer='adam', loss='mse', metrics=['mae'])

# Train the model
history = model.fit(X_train_scaled, y_train, epochs=50, validation_split=0.2, verbose=1)

# Evaluate the model on the test data
test_loss, test_mae = model.evaluate(X_test_scaled, y_test)

print(f'Test Loss: {test_loss}, Test MAE: {test_mae}')
