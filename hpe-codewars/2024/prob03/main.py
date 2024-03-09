while True:
    m = int(input())

    if m == -1:
        break

    if m == 1:
        print("You, 1 minute ago.")
    else:
        print(f"You, {m} minutes ago.")

