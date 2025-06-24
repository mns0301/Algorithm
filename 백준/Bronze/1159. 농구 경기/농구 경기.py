n, *l = open(0)
n = int(n)
li = list()
for i in range(26) :
    li.append(0)
for i in l :
    c = i[0]
    li[ord(c)-97] += 1
flag = 0
for i in range(26) :
    if (li[i] >= 5) :
        flag = 1
        print(chr(i+97), end="")
if (flag == 0) :
    print("PREDAJA")

