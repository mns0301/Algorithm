import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

while (True) :
	s = input().strip()

	if ('#' in s) :
		break

	ans = 0
	s = s.lower()
	ans += s.count('a')
	ans += s.count('e')
	ans += s.count('i')
	ans += s.count('o')
	ans += s.count('u')
	print(ans)
