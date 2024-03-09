from os import walk

def parse_name(filename):
    pass

def output_name():
    pass

genres = []

while True:
    genre = input()
    if genre == "END":
        break

    genres.append(genre)

files = []
for (_, _, filenames) in walk("."):
    files.extend(filenames)
    break

for file in files:
    g, t, a = parse_name()

    if g is None:
        continue

    print(output_name(g, t, a))
