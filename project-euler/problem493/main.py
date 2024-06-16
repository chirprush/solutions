# Note: This brute force solution actually misses the fact that you can compute
# the expected value using math without having to compute anything, which is
# really cool. Look into the thread later because it seems useful to learn such
# an approach.

from math import comb, factorial

def count(n, s=0, numbers=None):
    numbers = numbers or []
    
    if n == 0:
        prod = 1

        for i in numbers:
            prod *= comb(10, i)

        return prod

    total = 0

    for i in range(max(1, 20 - s - 10 * (n-1)), min(10, 20 - s) + 1):
        total += count(n - 1, s + i, [*numbers, i])

    return total

total = 0

for i in range(1, 8):
    total += i * comb(7, i) * count(i)
    # total += comb(7, i) * count(i)

total /= comb(70, 20)

print(total)
