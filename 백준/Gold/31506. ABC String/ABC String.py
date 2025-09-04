a=[b:=0]*3
for i in input():
	a[ord(i)-65]+=1
	b=max(b,max(a)-min(a))
print(b)