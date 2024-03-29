import galois
import numpy as np
print("Loaded modules")

MOD = 7514777789

points = []

for line in open('test.txt', 'r').read().strip().split('\n'):
    x, y = line.split(' ')
    points.append((int(x), int(y)))

GF = galois.GF(MOD)

matrix = []
solution = []
for point in points:
    x, y = point
    solution.append(GF(y % MOD))

    row = []
    for i in range(len(points)):
        row.append(GF(pow(x, i, MOD)))
    
    matrix.append(GF(row))

print(np.linalg.solve(GF(matrix), GF(solution)).tolist()[:-1])
# open('output.bmp', 'wb').write(bytearray(np.linalg.solve(GF(matrix), GF(solution)).tolist()[:-1]))
