from math import ceil

input()
state = input()

blocks = []
ends = []

current = 0
end = False
for i, c in enumerate(state):
    if c == '1':
        current += 1

        if i == 0:
            end = True
    elif current > 0:
        if end:
            ends.append(current)
        else:
            blocks.append(current)
        end = False
        current = 0

if current > 0:
    ends.append(current)

times = [(i - 1) // 2 for i in blocks]

if not ends:
    t_max = min(times)
    print(sum(i - 2 * t_max for i in blocks))
else:
    ends_max = min(ends) - 1

    if times:
        t_max = min(times)
        best_time = min(ends_max, t_max)
    else:
        best_time = ends_max

    sums = []
    for t in range(0, best_time + 1):
        S = sum(i - 2 * t for i in blocks)

        for e in ends:
            S += ceil(e / (2 * t + 1))

        sums.append(S)

    print(min(sums))

"""
times = [(i - 1) // 2 for i in blocks]
T = min(times)

if ends:
    Tend = max(min(*ends) - 1, T)
else:
    Tend = T

sums = []
print(sums)

for t in range(T, Tend + 1):
    sums.append(sum(i - 2 * t for i in blocks))
"""
