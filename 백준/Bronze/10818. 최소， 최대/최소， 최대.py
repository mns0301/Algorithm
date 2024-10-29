N = int(input())
max = -1000000
min = 1000000
li = list(map(int, input().split()))
for i in range(N):
	if li[i] < min:
		min = li[i]
	if li[i] > max:
		max = li[i]
print(min, max)
