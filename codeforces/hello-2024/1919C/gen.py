a = [ 11, 9, 4, 6, 12, 8, 10, 10, 8, 5, 9, 7, 5, 7 ]

def penalty(b):
    count = 0
    for i in range(len(b) - 1):
        if b[i] < b[i+1]:
            count += 1

    return count

def bit_at(b, i):
    return (b >> i) & 1

M = len(a)

for i in range(2 ** len(a)):
    s = []
    t = []

    for j, v in enumerate(a):
        if bit_at(i, j):
            s.append(v)
        else:
            t.append(v)

    P = penalty(s) + penalty(t)
    print((s, t), P)
    M = min(M, P)

print(M)
