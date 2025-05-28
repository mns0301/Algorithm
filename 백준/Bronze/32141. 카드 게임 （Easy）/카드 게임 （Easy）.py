n,h = map(int, input().split())
li = list(map(int, input().split()))
for i in range(n) :
    h -= li[i]
    if (h <= 0) :
        print(i+1)
        break
if (h > 0) :
    print(-1)