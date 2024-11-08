import sys
import math
input = sys.stdin.readline
import heapq
from collections import deque
INF = sys.maxsize

def fibo(n) :
	if (n in memo) :
		return memo[n]
	
	if (n%2 == 1) :
		memo[n] = (fibo(n//2+1)**2 + fibo(n//2)**2)%1000000007
	else :
		memo[n] = fibo(n//2)*(2*fibo(n//2-1)+fibo(n//2))%1000000007

	return memo[n]

n = int(input())
memo = {1 : 1, 0 : 0}

print(fibo(n))

# F[2n] = F[n]x(2F[n-1] + F[n])
# F[2n+1] = F[n+1]^2 + F[n]^2