from sympy import divisors

solutions = set()

for c in range(3, 21):
    N = 5 * c * (c - 2)
    A = 2 * c - 5
    B = 5 * (c - 2)

    print(f"Case c = {c}: ({A}a - {B})({A}b - {B}) = {N}")
    found = False

    for d in divisors(N):
        g = N // d
        if g < d:
            break
        if (d + B) % A == 0 and (g + B) % A == 0:
            a, b = (d + B) // A, (g + B) // A
            S = a * b * c
            if S not in solutions:
                print(f"    ({(d + B) // A}, {(g + B) // A}, {c}) -> {S}")
                solutions.add(S)
                found = True

    if not found:
        print("    No new solutions")

    print()
