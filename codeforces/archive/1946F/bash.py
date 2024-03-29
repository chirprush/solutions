def bit(a, base, i):
    return a // pow(base, i) % base

def to_base(a, base, pad):
    output = ""

    for i in range(pad):
        output = str(bit(a, base, i)) + output

    return output

def display(l, values, mask):
    output = ""

    for i, v in enumerate(l):
        output += str(values[bit(mask, len(values), i)]) + "*" + str(v) + " "

    return output

def result(l, values, mask):
    total = 0

    for i, v in enumerate(l):
        total += values[bit(mask, len(values), i)] * v

    return total

# So yeah, it's probably not linear in the prefix segments
tests = [([5, 9, 6, 1, 4, 15], 3), ([15, 5, 0, 7, 13, 0], 5), ([0, 20, 0, 0, 20, 0], 20), ([0, 14, 6, 0, 5, 15], 5)]
N = len(tests[0][0])
values = [0, 1, 2, -1, -2]
solutions = set(range(len(values) ** N))

for l, correct in tests:
    sub = set()
    for i in range(len(values) ** N):
        if (result(l, values, i) == correct):
            sub.add(i)
            # print(display(l, values, i))
            # print(to_base(i, len(values), 8), i)
    solutions.intersection_update(sub)

print(solutions)
