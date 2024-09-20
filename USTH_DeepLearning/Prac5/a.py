import numpy as np
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from math import *

X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])  
y = np.array([[0], [1], [1], [0]])  
model = Sequential()
model.add(Dense(2, input_dim = 2, activation = "sigmoid")) 
model.add(Dense(1, activation = "sigmoid"))  

model.compile(loss = "mean_squared_error", optimizer = "adam", metrics = ["accuracy"])
model.fit(X, y, epochs = 1000, verbose = 0)

predictions = model.predict(X)
res = round(predictions)

for i in range(len(X)):
    print(f"Input: {X[i]} -> Predicted: {res[i]} | Expected: {y[i]}")

