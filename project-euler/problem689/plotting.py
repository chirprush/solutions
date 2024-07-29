import matplotlib

matplotlib.use("tkagg")

import matplotlib.pyplot as plt
from random import randint

def random_point(prec):
    x = 0
    y = 0

    for i in range(1, prec + 1):
        bit = randint(0, 1)

        x += bit * 2 ** (-i)
        y += bit / i ** 2

    return (x, y)

N = 10000

plt.axline((0, 0.5), (1, 0.5))

for i in range(N):
    x, y = random_point(200)

    plt.plot(x, y, "bo")

# plt.gca().set_aspect('equal')
plt.show()
