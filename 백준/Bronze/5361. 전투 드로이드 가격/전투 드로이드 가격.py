import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

n  = int(input())
for i in range(n):
	li = list(map(int, input().split()))
	li[0] *= 350.34
	li[1] *= 230.90
	li[2] *= 190.55
	li[3] *= 125.30
	li[4] *= 180.90
	print("${0:.2f}".format(round(sum(li), 2)))
	
	