n = int(input())
m = 1e9
for i in range(n) :
    a,b = map(int, input().split())
    if (a > b) :
        continue
    if (b < m) :
        m = b
print(m if m != 1e9 else -1)