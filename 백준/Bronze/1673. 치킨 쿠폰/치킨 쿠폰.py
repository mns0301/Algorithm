li = open(0)
for i in li :
    n,k = map(int, i.split())
    s = n
    for j in range(100) :
        n += s//k
        s += s//k - s//k*k
    print(n)
        