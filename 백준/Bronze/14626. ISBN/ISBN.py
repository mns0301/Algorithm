s = input()
mul = 1
t = 0
for i in range(13) :
	if (s[i] == '*') :
		if (i%2 == 1) :
			mul = 3
	elif (i % 2 == 1) :
		t += int(s[i]) * 3
	else :
		t += int(s[i])
m = (10 - t % 10) % 10
for i in range(10) :
	if (i * mul % 10 == m) :
		print(i)