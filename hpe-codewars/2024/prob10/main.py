from re import findall

while True:
    line = input()

    if line == "END":
        break

    a, b, c = findall(r"-?\d+", line)
    a, b, c = int(a), int(b), int(c)

    if a + b == c:
        print("CORRECT")
    else:
        print(f"WRONG: {a}+{b}={a+b}")
