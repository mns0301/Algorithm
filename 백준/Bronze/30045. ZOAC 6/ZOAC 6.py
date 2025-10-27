n = int(input())
ans= 0
for i in range(n) :
    s = input()
    if ("01" in s or "OI" in s) :
        ans += 1
print(ans)