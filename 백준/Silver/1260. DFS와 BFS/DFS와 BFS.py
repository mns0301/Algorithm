import sys
import math
input = sys.stdin.readline
import heapq
from collections import deque
INF = sys.maxsize

def dfs(v) :
	# if (dfs_visit[v]) :
	# 	return
	
	dfs_visit[v] = 1
	print(v, end= " ")

	for idx in graph[v] :
		if (dfs_visit[idx] == 0) :
			dfs(idx)

	return

def bfs(v) :
	q = deque()
	q.append(v)
	bfs_visit[v] = 1

	while (q) :
		tmp = q.popleft()
		
		print(tmp, end= " ")

		for idx in graph[tmp] :
			if bfs_visit[idx] == 0 :
				bfs_visit[idx] = 1
				q.append(idx)
	return


n, m, v = map(int, input().split())

bfs_visit = [0] * (n + 1)
dfs_visit = [0] * (n + 1)
graph = [[] for _ in range(n+1)]
for i in range(m) :
	x, y = map(int, input().split())
	graph[x].append(y)
	graph[y].append(x)

for tmp in graph :
	tmp.sort()

dfs(v)
print()
bfs(v)