import sys
input = sys.stdin.readline
n = int(input())
s = - n + 1
for i in range(n) :
    s += int(input())
print(s)