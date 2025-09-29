n = int(input())
if (n%4) in [1,2,3] :
	print(-1)
else :
	for  i in range(n//4) :
		print("daaa"*(n//4))
		print("ddab"*(n//4))
		print("dcbb"*(n//4))
		print("cccb"*(n//4))