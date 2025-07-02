t = int(input())
for i in range(t) :
    s = int(input())
    o = int(input())
    for j in range(o) :
        a,b = map(int, input().split())
        s += a*b
    print(s)