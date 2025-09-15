n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in a:
	flag = 0
	if (i == 1) : continue
	for j in range(2, i):
		if (i%j ==0): flag = 1
	if (flag == 0) :
		ans+=1
print(ans)