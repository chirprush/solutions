firsts = 0
firstns = 0

while True:
    a, b = [int(i) for i in input().split(" ")]

    if a == 0 and b == 0:
        break

    if firsts == 0 and firstns == 0:
        firsts = a
        firstns = b
        continue

    
    print(int((10 ** 9 * a + b - (10 ** 9 * firsts + firstns)) / 10 ** 6))

    firsts = a
    firstns = b
