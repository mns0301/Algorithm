import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

a, b = map(float, input().split())
print(a+b - math.sqrt(a**2+b**2))