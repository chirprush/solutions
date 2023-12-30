def solve(n):
    if n == 1:
        print(1)
        return
    print(int(196 * 10 ** (n - 3)))

    N = n // 2

    for i in range(N):
        S = 10 ** N
        print((S + 3 * 10 ** i) ** 2)

    for i in range(N):
        S = 3 * 10 ** N
        print((S + 10 ** i) ** 2)

t = int(input())

for _ in range(t):
    solve(int(input()))
