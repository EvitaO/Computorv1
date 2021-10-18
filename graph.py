import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-100,100, num=200)

def y(x):
    return np.power(x, 2) * 0.3 + 5 * x

plt.plot(x, y(x), label='0.3 * X^2 + 5 * X^1')

plt.title("graph")
plt.xlabel('x axis')
plt.ylabel('y axis')
plt.axvline()
plt.axhline()

plt.grid(alpha=.4, linestyle='--')

plt.legend()
plt.show()