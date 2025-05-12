x,*l=open(0)
a,b=map(int,x.split())
e,f=[0]*1000001,0
for k in l:c,d=map(int,k.split());e[c]+=1;e[d]-=1
for i in e:f+=i if i>0 else 0
print(f)