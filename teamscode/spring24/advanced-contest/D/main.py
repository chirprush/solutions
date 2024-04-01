from math import log10

t = int(input())

for _ in range(t):
    n, k = [int(i) for i in input().split(" ")]
    x = {}
    total = {}

    for i in range(12):
        x[i] = {}
        total[i] = {}

    keys = [int(i) for i in input().split(" ")]
    values = set(keys)

    for i in keys:
        power = int(log10(i)) + 1

        if i in x[power]:
            x[power][i] += 1
        else:
            x[power][i] = 1

        if (i % k) in total[power]:
            total[power][i % k] += 1
        else:
            total[power][i % k] = 1

    count = 0

    powers = [pow(10, i, k) for i in range(0, 12)]
    # a = -b * powers[floor(log10(a)) + 1] (mod k)

    for b in values:
        for a_power, power in enumerate(powers):
            a_residue = (-power * b) % k
            b_power = int(log10(b)) + 1

            b_residue = b % k

            if a_power not in total or a_residue not in total[a_power]:
                continue

            # If a = b (mod k) then there are two cases
            # -> a = b, for which we need to account for distinct pandas
            # -> a != b, for which we just multiply like normal

            # For the first case, we want something like
            # count += total[b] * (total[b] - 1)
            # which is fine, but we need to know when a = b.
            # or we can just add them all and then subtract off the one case
            # where they're equal

            # For the second case (as well as when the initial condition
            # doesn't hold) it's just
            # count += total[a] * total[b]

            if (a_residue == b_residue and a_power == b_power):
                count += x[b_power][b] * total[a_power][a_residue] - x[b_power][b]
            else:
                count += x[b_power][b] * total[a_power][a_residue]

    print(count)
