while True:
    line = input()
    
    if line == "STOP":
        break

    last = ""

    for i in line:
        if i != last:
            last = i
            print(i, end="")
    print()
