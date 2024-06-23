total = 0

n = 10 ** 6
M = 10 ** 9 + 7

for k in range(1, n + 1):
    result = 1 - pow((1 - k ** 2) % M, n + 1, M)
    result %= M

    result *= pow(k ** 2 % M, -1, M)
    result %= M

    result -= 1
    result %= M

    total += result
    total %= M

print(total)
