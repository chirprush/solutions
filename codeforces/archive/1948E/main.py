from itertools import permutations

def max_cost(a):
    n = len(a)
    c = 0

    for i in range(n):
        for j in range(i + 1, n):
            c = max(c, abs(j - i) + abs(a[j] - a[i]))

    return c

n = 6
p = permutations(list(range(1, n + 1)))

for a in p:
    cost = max_cost(a)
    if cost == n:
        print(a)
    elif cost < n:
        print("Unconjectured case")
