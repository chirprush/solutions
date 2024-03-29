from math import log2, ceil

t = int(input())

# I really hope floating point errors aren't doing me in because that would be
# severely unfortunate

# It seems to be so; that is severely severe
for _ in range(t):
    n = int(input())
    a = [Decimal(i).ln() / Decimal(2).ln() for i in input().split(" ")]
    print(a)
    
    count = 0

    for i in range(1, n):
        diff = int(max(0, ceil(a[i-1] - a[i])))
        count += diff
        a[i] += diff

    print(count)
