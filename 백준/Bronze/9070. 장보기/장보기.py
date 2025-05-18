t = int(input())
for _ in range(t) :
    n = int(input())
    tmp = [0, -1]
    for i in range(n) :
        a,b = map(int, input().split())
        if (tmp[0] < a/b) :
            tmp = [a/b, b]
        elif (tmp[0] == a/b) :
            tmp[1] = min(b, tmp[1])
    print(tmp[1])