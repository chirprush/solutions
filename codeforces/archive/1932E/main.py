import sys
input = sys.stdin.readline

t = int(input())

# Bro ain't no way I actually have to manually implement like integers with arrays this is so sad
for _ in range(t):
    n = int(input())
    s = input()

    """
    total = 0
    p = 1
    c = ord('0')

    for i in range(n - 1, -1, -1):
        j = ord(s[i]) - c
        total += j * p
        p = p * 10 + 1
    """
    c = ord('0')

    total = 0
    total2 = 0
    for i in range(n):
        total += ord(s[i]) - c
        total2 += ord(s[i]) - c

        if i != n - 1:
            total = 10 * total + total2

    print(total)
