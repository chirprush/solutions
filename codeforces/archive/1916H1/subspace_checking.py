from math import prod

p = 2

# Just verifying that these are in fact integers
# and do look like the correct values, which they
# do :D
def sub(r, k):
    num = prod(p ** r - p ** i for i in range(k))
    den = prod(p ** k - p ** i for i in range(k))

    assert num % den == 0
    return num // den

n = 3

for r in range(n + 1):
    print(f"sub[{n}, {r}] = {sub(n, r)}")
