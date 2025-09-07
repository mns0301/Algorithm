d=[1]*101
for i in range(97):d[i+3]=d[i]+d[i+1]
for i in list(map(int,open(0)))[1:]:print(d[i-1])