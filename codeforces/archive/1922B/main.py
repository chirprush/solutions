from math import comb

t = int(input())

for _ in range(t):
    n = int(input())
    
    counts = {}

    a = [int(i) for i in input().split(" ")]

    for v in a:
        if v in counts:
            counts[v] += 1
        else:
            counts[v] = 1

    triangles = 0
    running = 0

    for ai in sorted(counts.keys()):
        c = counts[ai]
        triangles += running * comb(c, 2)
        triangles += comb(c, 3)

        running += c

    print(triangles)
