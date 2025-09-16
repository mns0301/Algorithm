a = int(input())
b = map(int, input().split())
c = 0
for i in b :
	if (i == 1) : 
		continue
	for j in range(2, i) :
		if i%j == 0:
			break
	else :
		c += 1
	
print(c)