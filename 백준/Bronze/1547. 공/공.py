import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

li = [0,1,0,0]
m = int(input())
for i in range(m) :
	x, y = map(int, input().split())
	li[x],li[y] = li[y], li[x]

print(li.index(1))