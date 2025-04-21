import sys
input = sys.stdin.readline

N, M = map(int, input().split())
end = dict()
ans = []

for _ in range(M):
    k, s, e = map(int, input().split())
    last = end.get(k, 0)
    if last <= s:
        ans.append("YES")
        end[k] = e  # 끝나는 시간 갱신
    else:
        ans.append("NO")

print('\n'.join(ans))
