n, m = [int(i) for i in input().split(" ")]

def f(n, m):
    b = pow(2, n, m)
    c = (pow(2, n - 1, m) - 1) if n > 0 else 0
    return (2 * b + c) % m

print(f(n, m))
