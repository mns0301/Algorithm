a,b,c=map(int, input().split())
li = [0 for _ in range(100)]
for i in range(1, a+1) :
    for j in range(1, b+1) :
        for k in range(1, c+1) :
            li[i+j+k] += 1
tmp = 3
for i in range(3, 100) :
    if (li[i] > li[tmp]) :
        tmp = i
print(tmp)