import sys
input = sys.stdin.readline

def check(P, p):
    dp = [0] * n
    now = P
    dp[0] = P
    # rev = now
    for i in range(1, len(p)):
        if now >= p[i]:
            now = p[i] + P
            dp[i] = now
            # rev = now
        else:
            v = P - (p[i] - now)
            if v >= 0: 
                now += v
                dp[i] = now
                if (now < p[i]) :
                    dp[i] = p[i]
                    # rev = p[i]
                    # return dp
                # rev = max(now, p[i])
                # rev = now
            else: return dp
    
    return dp

L, n = map(int, input().split())
p = list(map(int, input().split()))
# dp = [0 for i in range(n)]
pp = [L - i for i in p[::-1]]
# dpr = [0 for i in range(n)]

left = 0
right = L

while left + 1 < right:
    mid = (left+right)//2
    l = check(mid, p)
    # pr = []
    # for x in range(i + 1, n):
    #     pr.append(p[x])
    # print(pr)
    # pr = [L - i for i in pr[::-1]]
    r = check(mid, pp)
    # print(mid)
    # print("l: ", l)
    # print("r: ", r)
    flag = 0
    for i in range(n) :
        xx = l[i] + r[n - i - 2]
        if (xx >= L) : flag = 1
    if (flag): right = mid
    else: left = mid

    # if l + r >= L: right = mid
    # else: left = mid

print(right)