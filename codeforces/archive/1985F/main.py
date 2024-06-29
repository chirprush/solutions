from math import gcd, ceil

t = int(input())

def lcm(a, b):
    return a * b // gcd(a, b)

def score(t, a, b):
    return sum(a[i] * (t // c[i] + 1) for i in range(len(a)))

def search(lower, upper, h, a, c):
    if lower >= upper:
        return lower

    mid = (lower + upper) // 2
    mscore = score(mid, a, c)

    if mscore >= h:
        return search(lower, mid, h, a, c)
    else:
        return search(mid + 1, upper, h, a, c)

for _ in range(t):
    h, n = [int(i) for i in input().split(" ")]

    a = [int(i) for i in input().split(" ")]
    c = [int(i) for i in input().split(" ")]

    l = 1

    for i in c:
        l = lcm(l, i)

    healthper = score(l, a, c) - sum(a)

    lower = max(0, l * (h // healthper - 1))
    upper = l * ceil(h / healthper)

    print(1 + search(lower, upper, h, a, c))
