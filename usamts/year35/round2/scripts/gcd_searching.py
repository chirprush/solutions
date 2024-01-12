from math import gcd

nums = [20, 21, 22, 23, 24, 25, 27, 28, 30, 32, 33, 35]

coprime_to = [int(i) for i in (input("Coprime to: ") or "1").split(" ")]
noncoprime_to = [int(i) for i in (input("Not coprime to: ") or "0").split(" ")]

matched = []

for n in nums:
    coprime_cond = all(gcd(n, i) == 1 for i in coprime_to)
    noncoprime_cond = all(gcd(n, i) != 1 for i in noncoprime_to)
    if coprime_cond and noncoprime_cond:
        matched.append(n)

print(matched)
