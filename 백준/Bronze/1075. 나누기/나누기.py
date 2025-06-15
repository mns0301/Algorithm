a = int(input())//100*100
b = int(input())
for i in range(100) :
	if (a + i) % b == 0 :
		print("{:02d}".format((a+i)%100))
		break