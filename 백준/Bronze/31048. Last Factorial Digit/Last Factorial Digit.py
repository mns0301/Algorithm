t = int(input())

for i in range(t) :
    n = int(input())
    c = 1
    for j in range(1, n+1) :
        c = (c*j)%10
    print(c)