li = open(0)

for name in li :
    for i in name :
        if (i == 'i') :
            i = 'e'
        elif (i == 'e') :
            i = 'i'
        elif (i == 'I') :
            i = 'E'
        elif (i == 'E') :
            i = 'I'
        print(i, end="")