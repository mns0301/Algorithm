import sys
input = sys.stdin.readline

n = int(input())%3
print("S" if n == 0 else ("U" if n == 1 else "O"))