li = list(map(int, input().split()))
x = [0, 500, 800, 1000]
s = 5000
for i in li:
	s -= x[i]
print(s)