for i in range(3) :
	li = list(map(int, input().split()))
	s = li.count(0)
	c = 'A'
	if (s == 2) : c = 'B'
	if (s == 3) : c = 'C'
	if (s == 4) : c = 'D'
	if (s == 0) : c = 'E'
	print(c)