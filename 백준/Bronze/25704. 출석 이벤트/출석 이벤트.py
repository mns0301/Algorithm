cou = int(input())
pri = int(input())
ans = pri

if (cou >= 5) :
	ans = max(0, pri-500)
if (cou >= 10) :
	ans = min(ans, int(pri*0.9))
if (cou >= 15) :
	ans = min(ans, max(0, pri-2000))
if (cou >= 20) :
	ans = min(ans, int(pri*0.75))
print(ans)
