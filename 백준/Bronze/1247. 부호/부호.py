a = 3
while (a) :
	a-=1

	n = int(input())
	sum = 0
	for i in range(n) :
		tmp = int(input())
		sum += tmp
	if (sum > 0) : print('+')
	elif (sum < 0) : print('-')
	else : print(0)