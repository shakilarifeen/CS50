while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            break
    except ValueError:
        print("")

for i in range(height):
    blank = (height) - (i+1)
    print(" "*blank + "#"*(i+1) + "  " + "#"*(i+1))
