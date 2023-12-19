from math import inf, ceil

def solve(N, h, a, t):
    index_map = [0] * N
    for index_in, index_out in enumerate(t):
        index_map[index_out] = index_in

    d_lower = 0
    d_upper = inf

    if N == 1:
        return -1 if t[0] != 0 else 0

    for j in range(1, N):
        i = index_map[j]
        prev = index_map[j - 1]

        h_prev = h[prev]
        a_prev = a[prev]

        h_i = h[i]
        a_i = a[i]

        # print(f"(h_prev, a_prev): ({h_prev}, {a_prev})")
        # print(f"(h_i, a_i): ({h_i}, {a_i})")

        # a_i = a_2
        # h_i = h_2

        # a_prev = a_1
        # h_prev = h_1
        if a_i >= a_prev and h_i >= h_prev:
            return -1
        elif a_i >= a_prev and h_i < h_prev:
            # This gives an upper bound and a lower of 0 which we'll max with
            # current lower
            d_upper = min((h_prev - h_i) // (a_i - a_prev), d_upper)
        elif a_i < a_prev and h_i >= h_prev:
            # This gives lower bound but not upper
            A = 1 + (h_prev - h_i) // (a_i - a_prev)
            d_lower = max(int(A), d_lower)
        elif a_i < a_prev and h_i < h_prev:
            # This gives no bound
            continue

        if d_upper < d_lower:
            return -1

    return d_lower

T = int(input())

for _ in range(T):
    N = int(input())
    h = [int(i) for i in input().split(" ")]
    a = [int(i) for i in input().split(" ")]
    t = [int(i) for i in input().split(" ")]

    print(solve(N, h, a, t))
