# Thankfully this is prime
M = 1123455689

N = 18

factorials_mod = [1]

for i in range(1, N + 1):
    factorials_mod.append(factorials_mod[i-1] * i % M)

factorials_inv = [pow(i, -1, M) for i in factorials_mod]

digit_pows = [pow(10, i, M) for i in range(N)]

def sum_sorted(composition):
    mult = factorials_mod[N]

    for i in composition:
        mult = mult * factorials_inv[i] % M

    core = 0
    power = 0
    index = 9

    while index >= 0 and power < N:
        while composition[index]:
            core += index * digit_pows[power] % M
            core %= M
            composition[index] -= 1

            power += 1

        index -= 1

    return mult * core % M

def solve(n, accumulated, composition):
    if n == 0:
        return sum_sorted(composition)
    elif n == 1:
        return solve(n - 1, N, [*composition, N - accumulated])

    total = 0

    for i in range(N - accumulated + 1):
        total += solve(n - 1, accumulated + i, [*composition, i])
        total %= M

    return total

def brute_force_solve():
    count = 0

    for i in range(10 ** N):
        count += int(''.join(sorted(str(i))))

    return count

print(solve(10, 0, []))
# print(brute_force_solve())
