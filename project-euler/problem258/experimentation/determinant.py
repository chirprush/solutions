import numpy as np

def basis_vec(n, i):
    return [1 if j == i else 0 for j in range(n)]

data = []

for i in range(1999):
    data.append(basis_vec(2000, i + 1))

last = basis_vec(2000, 0)
last[1] = 1

data.append(last)

A = np.array(data, dtype=np.int64)

print(A)

print(np.linalg.det(A))
