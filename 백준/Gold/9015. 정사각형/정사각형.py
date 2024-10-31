import sys
import math
input = sys.stdin.readline
import heapq
from collections import deque
INF = sys.maxsize

def fun() :
	n = int(input())
	max_size = 0
	dot = [list(map(int, input().split())) for _ in range(n)]
	s = set()
	for i in range(n):
		s.add((dot[i][0], dot[i][1]))

	for i in range(n):
		for j in range(i+1, n):
			p1_x = dot[i][0] #-3
			p1_y = dot[i][1] #-2
			p2_x = dot[j][0] #3
			p2_y = dot[j][1] #2
			mid_x = (p1_x + p2_x) / 2
			mid_y = (p1_y + p2_y) / 2
			p3_x = mid_x + mid_y - p1_y #-2
			p3_y = mid_y + mid_x - p2_x #3
			p4_x = mid_x + mid_y - p2_y #2
			p4_y = mid_y + mid_x - p1_x #-3
			if ((p3_x, p3_y) in s) and ((p4_x, p4_y) in s) :
				max_size = max(max_size, (p1_y-p3_y)**2 + (p1_x-p3_x)**2)

	print(int(max_size))
	return

t = int(input())
for i in range(t):
	fun()