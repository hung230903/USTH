def f(x):
    return x**2

def f_derivative(x):
    return 2*x

x = -2
learning_rate = 0.1

for i in range(10): 
    gradient = f_derivative(x)
    x = x - learning_rate*gradient
    
 