n = int(input())

for i in range(n):
    name, years, months = input().split(" ")
    years = int(years)
    months = int(months)

    to = (25 * 12 - (years * 12 + months))
    print(name, to)
