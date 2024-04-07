from math import sqrt

def d(n):
    divisors = 0
    for i in range(1, round(sqrt(n)) + 1):
        if (n % i == 0):
            divisors += 1 + (n // i != i)

    return divisors

x = int(input())

if x == 1:
    print(1)
    exit()

for f in range(60, 1, -1):
    n = x ** (1 / f)

    # Hmmmm this WAs, likely due to precision issues I suppose
    if abs(n - round(n)) < 1e-9 and d(round(n)) == f:
        print(round(n))
        exit()

print(-1)
