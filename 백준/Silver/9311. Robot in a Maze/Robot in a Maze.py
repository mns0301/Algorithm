import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

def Dijk(ty, tx, visited, li) :
	pos = []
	heapq.heappush(pos, [0, ty, tx])
	dy = [-1, 1, 0, 0]
	dx = [0, 0, 1, -1]
	visited[ty][tx] = 1

	while(len(pos)) :
		now = heapq.heappop(pos)
		depth = now[0]
		y = now[1]
		x = now[2]
		
		if(li[y][x] == 'G') :
			return depth

		for i in range(4) :
			yy = y+dy[i]
			xx = x+dx[i]
			if (visited[yy][xx] == 0 and (li[yy][xx] != 'X')) :
				heapq.heappush(pos, [depth+1, yy, xx])
				visited[yy][xx] = 1

	return 0



t = int(input())
for x in range(t) :
	r, c = map(int, input().split())

	visited = [[0]*(c+2) for _ in range(r+2)]
	for i in range(r+2) :
		visited[i][0] = 1
		visited[i][c+1] = 1
	for i in range(c+2) :
		visited[0][i] = 1
		visited[r+1][i] = 1

	li = []
	li.append('X'*(c+2))
	for i in range(1, r+1) :
		tmp = 'X'+input().strip()+'X'
		li.append(tmp)
	li.append('X'*(c+2))

	y, x = -1, -1
	for i in range(1, r+1) :
		for j in range(1, c+1) :
			if (li[i][j] == 'S') :
				y, x = i, j

	length = Dijk(y, x, visited, li)

	if (length == 0) :
		print("No Exit")
	else :
		print("Shortest Path:", length)