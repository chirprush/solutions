from re import findall

def solve1(line, i):
    blues = all(map(lambda a: int(a) <= 14, findall(r'(\d+) blue', line)))
    greens = all(map(lambda a: int(a) <= 13, findall(r'(\d+) green', line)))
    reds = all(map(lambda a: int(a) <= 12, findall(r'(\d+) red', line)))

    if blues and greens and reds:
        return i
    return 0

def solve2(line, i):
    blue = max(map(int, findall(r'(\d+) blue', line)))
    green = max(map(int, findall(r'(\d+) green', line)))
    red = max(map(int, findall(r'(\d+) red', line)))

    return blue * green * red
    

n = int(input())
total = 0

for i in range(1, n + 1):
    line = input()

    # total += solve1(line, i)
    total += solve2(line, i)

print(total)
