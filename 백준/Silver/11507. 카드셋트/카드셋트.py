import sys
import math
input = sys.stdin.readline
import heapq
from collections import deque
INF = sys.maxsize

li = input().strip()

d = {"P":0, "K":1, "H":2, "T":3}
a = [[0]*14 for _ in range(4)]
for i in range(0, len(li), 3) :
	str1 = d[li[i]]
	num = int(li[i+1:i+3])
	if a[str1][num] :
		print("GRESKA")
		exit()
	else : 
		a[str1][num] = 1

for i in range(4) :
	cnt = 13
	for j in range(1, 14) :
		if a[i][j] == 1 :
			cnt-=1
	print(cnt, end=" ")