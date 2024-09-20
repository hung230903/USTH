import matplotlib.pyplot as plt

x = [8.00, 6.40, 5.12, 4.10, 3.28, 2.62, 2.10, 1.68, 1.34, 1.07]
fx = []

for i in x:
  fx.append(i * i)

print(fx)

plt.xlabel("x")
plt.ylabel("y")
plt.plot(x, fx)
plt.show()