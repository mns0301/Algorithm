n = int(input())

for i in range(n) :
	print("*"*(i+1), end="")
	print(' '*(2*(n-i)-2), end="")
	print("*"*(i+1))
for i in range(n-2, -1, -1) :
	print("*"*(i+1), end="")
	print(' '*(2*(n-i)-2), end="")
	print("*"*(i+1))