s,a,b=input(),[0]*3,0
for i in s:
	a[ord(i)-65]+=1
	b=max(b,max(a)-min(a))
print(b)