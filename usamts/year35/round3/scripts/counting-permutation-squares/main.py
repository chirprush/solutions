# See https://oeis.org/A002860
# Brute force is definitely not a viable option
from itertools import permutations
from math import prod

p = [2, 3, 5, 7]
P = prod(p)

perms = list(permutations(p))

def is_valid(A):
    return all(prod(row) == P for row in A) and all(prod(A[j][i] for j in range(len(p))) == P for i in range(len(p)))

count = 0

for p1 in perms:
    for p2 in perms:
        for p3 in perms:
            for p4 in perms:
                A = [p1, p2, p3, p4]
                if is_valid(A):
                    count += 1
                    print(A)

print(count)
