n = int(input())
for i in range(1, 1000001) :
	if (i*i > n) :
		print("The largest square has side length {}.".format(i-1))
		break