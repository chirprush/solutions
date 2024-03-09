m, b, size = [int(i) for i in input().split(" ")]

def format_num(n):
    return f"{n:02}"

lines = [f"y = {m}x+{b}"]

for y in range(size, -1, -1):
    line = ""
    for x in range(0, size + 1):
        here = y == m * x + b

        if x == 0 and not here:
            line += format_num(y)
        elif x == 0 and here:
            line += format_num(y)[0] + "#"
        elif y == 0:
            line += format_num(x)
        elif here:
            line += " #"
        else:
            line += "  "

    lines.append(line)

for i in lines:
    # Just in case whitespace matters
    print(i.rstrip())
