from re import search

def f(n):
    return f"{n:.1f}"

line = input()

hpos = 0
apos = float(search(r"Start:(-?\d+\.\d)", line).group(1))
length = float(search(r"Length:(-?\d+\.\d)", line).group(1))
if search(r"Flashlight:(-?\d+\.\d)", line):
    flashlight = float(search(r"Flashlight:(-?\d+\.\d)", line).group(1))
else:
    flashlight = 1000000000

if search(r"Door:(-?\d+\.\d)", line):
    door = float(search(r"Door:(-?\d+\.\d)", line).group(1))
else:
    door = 1000000000

print(door)

hspeed = float(search(r"Run:(-?\d+\.\d)", line).group(1))
aspeed = float(search(r"Chase:(-?\d+\.\d)", line).group(1))
exit = float(search(r"Exit:(-?\d+\.\d)", line).group(1))

last_blinded = -10
last_blocked = -10

# Ok do the inputting later I guess
t = 1
hlines = ["HERO:"]
alines = ["ANIMATRONIC:"]

used_flashlight = False
used_door = False

while True:
    if apos >= hpos:
        hlines.append("OH NO!")
        alines.append("CAUGHT!")
        break
    elif hpos >= exit:
        hlines.append("MADE IT!")
        alines.append("MISSED!")
        break

    # can use flashlight iff there is no door between h and a
    # and also if we just reached it

    currently_blocked = (t - last_blocked) <= 2
    currently_blinded = (t - last_blinded) <= 1

    if currently_blocked:
        apos = door

    if not currently_blinded and not currently_blocked and flashlight <= hpos and not used_flashlight:
        used_flashlight = True
        last_blinded = t
        currently_blinded = True
        hlines.append(f"[flashlight used at {flashlight}]")
        alines.append(f"[blinded, stopped]")
    elif not currently_blocked and door - aspeed <= apos <= door and not used_door:
        used_door = True
        last_blocked = t
        currently_blocked = True
        alines.append(f"[door, stopped]")

    hlines.append(f"Time-{t:02}: {f(hpos)}->{f(hpos+hspeed)}")
    if not currently_blocked and not currently_blinded:
        alines.append(f"Time-{t:02}: {f(apos)}->{f(apos+aspeed)}")
    elif currently_blinded:
        alines.append(f"Time-{t:02}: blinded")
    elif currently_blocked:
        alines.append(f"Time-{t:02}: blocked")

    if hpos <= door <= hpos + hspeed:
        hlines.append(f"[door shut at {door}]")


    hpos += hspeed

    if not currently_blocked and not currently_blinded:
        apos += aspeed

    t += 1

for i in hlines:
    print(i)

print()

for i in alines:
    print(i)
