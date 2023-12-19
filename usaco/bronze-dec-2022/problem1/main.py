input()
tuitions = [int(i) for i in input().split(" ")]
bins = {}

for t in tuitions:
    if t in bins:
        bins[t] += 1
    else:
        bins[t] = 1

costs = []
included = 0

for t in reversed(sorted(set(tuitions))):
    included += bins[t]

    costs.append((included * t, t))

profit, tuition = max(reversed(costs), key=lambda a: a[0])

print(profit, tuition)
