import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv("data.csv")

price = data["Price"]
square = data["Square "] 

plt.figure(figsize = (10, 5))
plt.scatter(square, price, color = "blue")
plt.xlabel("Square")
plt.ylabel("Price")

plt.show()
