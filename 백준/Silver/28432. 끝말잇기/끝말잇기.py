n = int(input())
li = []
for i in range(n) :
    li.append(input())
m = int(input())
tmp = []
for i in range(m) :
    tmp.append(input())

if (n==1) :
    print(tmp[0])
    exit(0)
 
for i in range(n) :
    if (li[i] == '?') :
        if (i == 0) :
            for j in range(m) :
                if (tmp[j][-1] == li[i+1][0] and tmp[j] not in li) :
                    print(tmp[j])
        elif (i == n-1) :
            for j in range(m) :
                if (tmp[j][0] == li[i-1][-1] and tmp[j] not in li) :
                    print(tmp[j])
        else :
            for j in range(m) :
                if (tmp[j][0] == li[i-1][-1] and tmp[j][-1] == li[i+1][0] and tmp[j] not in li) :
                    print(tmp[j])
        break
