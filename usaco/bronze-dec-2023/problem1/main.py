input()
cows = [int(i) for i in input().split(" ")]
canes = [int(i) for i in input().split(" ")]

for cane in canes:
    height = 0

    for i, cow in enumerate(cows):
        if cow > height and cane > 0:
            eaten = min(cane, cow - height)
            height += eaten
            cows[i] += eaten
            cane -= eaten

for cow in cows:
    print(cow)
