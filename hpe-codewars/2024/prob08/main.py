l = input()
types = [0] * len(l)

letters = ""
numbers = ""

for i in range(len(l)):
    if l[i].isnumeric():
        numbers += l[i]
        types[i] = 1
    else:
        letters += l[i]

letters = sorted(letters)
numbers = sorted(numbers)

a = 0
b = 0

output = [""] * len(l)

for i in range(len(l)):
    if types[i] == 0:
        output[i] = letters[a]
        a += 1
    else:
        output[i] = numbers[b]
        b += 1

print("".join(output))
