t = int(input())
for i in range(t) :
    c = int(input())
    flag = 0
    for j in range(2, 1000000) :
        if (c % j == 0) :
            flag = 1
            break
    print("NO" if flag else "YES")