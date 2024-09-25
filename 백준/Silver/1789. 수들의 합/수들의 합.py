n = int(input())
a = 1
while (n > 0) :
	n -= a
	a+=1
if n==0 :
	print(a-1)
else :
	print(a-2)