# YOLO
N = int(input())
nums = {int(i) for i in input().split(" ")}

M = min(nums) // 4
S = 6

for i in range(4, M + 1):
    if len({j % i for j in nums}) <= 3:
        S += i

print(S)
