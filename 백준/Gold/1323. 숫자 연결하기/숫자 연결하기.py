import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

n, k = map(int, input().split())

sz = 10 ** len(str(n))
x = n%k

visited = [0] * k

for i in range(k) :
	if (x%k==0) :
		print(i + 1)
		break

	if (visited[x] == 1) :
		print(-1)
		break

	visited[x] = 1
	x = (n + x * sz) % k