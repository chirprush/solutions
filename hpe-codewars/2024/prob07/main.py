line = input()
blocks = []

for i in line:
    if not blocks or blocks[-1][1] != i:
        blocks.append([1, i])
    else:
        blocks[-1][0] += 1

n = [i for i in blocks if i[0] == 4]

if not n:
    print("No Four of a Kind")
    exit(0)

for i in blocks:
    if (i[0] == 4):
        print(i[1], end='')

print()
