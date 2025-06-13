t = int(input())
for i in range(t) :
    a = 0
    b = 1e9
    arr = list(map(int, input().split()))
    for c in arr :
        if (c % 2 == 0) :
            a += c
            b = min(b, c)
    print(a,b)
