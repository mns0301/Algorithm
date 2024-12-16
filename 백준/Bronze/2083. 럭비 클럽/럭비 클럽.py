while (1) :
    n, a, w = input().split()
    a = int(a)
    w = int(w)
    if (n =='#') :
        break
    if (a > 17 or w >= 80) :
        print(n, "Senior")
    else :
        print(n, "Junior")