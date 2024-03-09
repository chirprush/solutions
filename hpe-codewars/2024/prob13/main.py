lines = []

while True:
    try:
        lines.append(input().rstrip())
    except:
        break

width = max(len(i) for i in lines)
height = len(lines)

new_lines = []

new_lines.append("#" * width)

for i in range(height - 2):
    new_lines.append("#" + " " * (width - 2) + "#")

new_lines.append("#" * width)

if all(new_lines[i] == lines[i] for i in range(height)):
    print("Nothing to do")
else:
    for i in new_lines:
        print(i)
