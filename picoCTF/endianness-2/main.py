with open("challengefile", "rb") as f:
    b = f.read()

M = 4
output = bytearray()

while b:
    chunk = b[:M]
    for i in reversed(chunk):
        output.append(i)
    b = b[M:]

with open("outfile", "wb") as f:
    f.write(bytes(output))
