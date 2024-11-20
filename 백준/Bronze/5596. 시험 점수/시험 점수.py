import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

a = sum(map(int, input().split()))
b = sum(map(int, input().split()))

print(a if a > b else b)