# It's literally just MST what :sob:

n = 40
edges = []

with open("input.txt") as f:
    lines = f.readlines()

    for r, line in enumerate(lines):
        values = line.strip().split(",")

        for c, value in enumerate(values):
            if value == "-":
                continue

            if c <= r:
                continue

            edges.append((r, c, int(value)))

components = [i for i in range(n)]
edges.sort(key=lambda e: e[2])

# print(edges)

total = sum(e[2] for e in edges)
minimum = 0

result_graph = []

for e in edges:
    if components[e[0]] == components[e[1]]:
        continue

    minimum += e[2]
    result_graph.append(e)

    # print(e)

    old = components[e[1]]
    new = components[e[0]]

    for i in range(n):
        if components[i] == old:
            components[i] = new

    # print(components)

# print([("ABCDEFG"[a], "ABCDEFG"[b], w) for (a, b, w) in result_graph])
print(total - minimum)
