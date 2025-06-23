n, *l = open(0)
t = ""
n = int(n)
for i in range(len(l[0])) :
    flag = 0
    tmp = l[0][i]
    for j in range(1, n) :
        if (tmp != l[j][i]) :
            flag = 1
            break
    t += "?" if flag else l[0][i]
print(t)