import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

while (1) :
	a, b = map(int, input().split())
	if (a==0 and b==0) :
		break
	print(a+b)