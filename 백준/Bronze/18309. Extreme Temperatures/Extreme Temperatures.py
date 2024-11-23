t = []

while(1) :
	try :
		x = list(map(int, input()[11:].split()))
	except :
		break
	t += x

print(min(t), max(t))