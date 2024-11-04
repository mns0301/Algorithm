import sys
import math
input = sys.stdin.readline
import heapq
from collections import deque
INF = sys.maxsize

n = int(input())

arr = []

t1, t2 = map(int ,input().split())
arr.append([t1, t2])
for i in range(1, n) :
	x, y = map(int, input().split())
	arr.append([x, y])
arr.append([t1, t2])

fir = 0
sec = 0

for i in range(0, n) :
	fir += (arr[i][0] * arr[i+1][1])
	sec += (arr[i][1] * arr[i+1][0])

print(abs(fir-sec) / 2)