import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

s = input().strip()
li = [0] * 26

for i in s :
	li[ord(i) - 97] += 1

print(*li)