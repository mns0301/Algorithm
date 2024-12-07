import sys
input = sys.stdin.readline

a, b = map(int, input().split())
li = list(map(int, input().split()))

for i in range(5) :
	print(li[i] - a*b, end=" ")