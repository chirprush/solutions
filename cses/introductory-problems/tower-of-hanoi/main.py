def other(current, to):
    s = {1, 2, 3}
    s.remove(current)
    s.remove(to)

    return list(s)[0]

def solve(n, current, to):
    if n == 1:
        print(current, to)
        return

    solve(n - 1, current, other(current, to))
    print(current, to)
    solve(n - 1, other(current, to), to)

n = int(input())

print(2 ** n - 1)
solve(n, 1, 3)
