import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return x**2

def f_derivative(x):
    return 2*x

x = 10  
learning_rate = 0.1
loops = 10  

x_values = [x]
f_values = [f(x)]

for i in range(loops):
    gradient = f_derivative(x)
    x = x - learning_rate * gradient
    x_values.append(x)
    f_values.append(f(x))

plt.figure(figsize = (8, 6))
x_range = np.linspace(-10, 10, 100)
plt.plot(x_range, f(x_range), color = 'red')
plt.plot(x_values, f_values, linestyle = 'dashed', color = 'blue', marker ='o')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.show()



