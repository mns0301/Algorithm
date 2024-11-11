import sys
import math
import heapq
import bisect
from collections import deque
from collections import Counter
input = sys.stdin.readline
INF = sys.maxsize

a = int(input())
x = int(input())
b = int(input())
y = int(input())
t = int(input())
cost1 = a + max(0, (t-30)) * 21 * x
cost2 = b + max(0, (t-45)) * 21 * y
print(cost1, cost2)