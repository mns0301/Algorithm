s,n = map(int, input().split())
li = [0 for _ in range(s+1)]

for i in range(n) :
    a,b = map(int, input().split())
    for j in range(a, s+1, b) :
        li[j] = 1
c = 0
for i in range(1, s+1) :
    if (li[i] == 0) :
        c += 1
print(c)