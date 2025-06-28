n=1
while (1) :
    l = list(map(int, input().split()))
    if len(l)==1:
        break
    l.pop(0)
    t = len(l) - 1
    if (len(l) % 2 == 0) :
        m = (l[t//2] + l[t//2 + 1])/2
    else :
        m = l[(t+1)//2]
    print("Case " + str(n) + ": " + str(float(m)))
    n+=1
