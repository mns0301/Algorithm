a,b = map(int, input().split())
a,b = min(a,b), max(a,b)
print((b-a+1)*(b+a)//2)