x = int(input())
y = int(input())
t = 1
if (x < 0) : t+=1
if (y < 0) : 
	t+=1
	if (x > 0) :
		t += 2
print(t)