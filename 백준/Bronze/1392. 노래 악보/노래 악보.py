n, q = map(int, input().split())
li = [0 for _ in range(n + 1)]
for i in range(1, n + 1) :
    li[i] = li[i-1] + int(input())
for i in range(q) :
    t = int(input())
    for j in range(n + 1) :
        if (li[j] > t) :
            print(j)
            break