import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

n = int(input())

for i in range(n) :
	a, b = map(int, input().split())
	print(int(a*b/math.gcd(a,b)))