solution = [
    [3, 2, 2, 3, 3, 2, 3],
    [1, 3, 1, 1, 2, 1, 3],
    [1, 2, 2, 0, 3, 1, 2],
    [0, 3, 1, 1, 2, 3, 2],
    [2, 2, 3, 2, 0, 1, 0],
    [3, 0, 1, 1, 3, 1, 3],
    [3, 2, 2, 3, 2, 2, 3]
]

print("\\begin{tikzpicture}")

for ry, row in enumerate(solution):
    for x, value in enumerate(row):
        y = 6 - ry
        color = ["gray", "gblue", "ggreen", "gred"][value]
        num = ["", "1", "3", "5"][value]

        bx = 0.5 * x
        by = 0.5 * y
        print("    \\fill[%s] (%f, %f) rectangle (%f, %f);" % (color, bx, by, bx + 0.5, by + 0.5))

        if (num):
            print("    \\node at (%f, %f) {%s};" % (bx + 0.25, by + 0.25, num))

print("    \\draw[step=0.5cm, thick] (0, 0) grid (3.5, 3.5);")

print("\\end{tikzpicture}")
