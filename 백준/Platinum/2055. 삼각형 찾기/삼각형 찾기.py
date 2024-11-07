import sys
import math
input = sys.stdin.readline
import heapq
from collections import deque
INF = sys.maxsize
import math

n, m = map(int, input().split())
n += 1
m += 1
s = math.comb(n*m, 3)
s -= math.comb(n,3) * m
s -= math.comb(m,3) * n

for i in range(2, n) :
	for j in range(2, m) :
		s -= 2 * (n - i) * (m - j) * (math.gcd(i, j) - 1)

print(s)