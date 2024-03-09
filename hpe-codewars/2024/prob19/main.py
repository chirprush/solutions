minutes = float(input())

days = minutes // (24 * 61.625)
minutes -= days * 24 * 61.625
hours = (minutes // 61.625) % 24
minutes -= hours * 61.625
seconds = round((minutes * 60) % 60, 1)

print(f"{int(days)} days {int(hours)} hours {int(minutes) % 60} minutes {seconds} seconds")
