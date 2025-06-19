n, *l = open(0)
for i in l :
    i = list(map(int, i.split()))
    print(max(1, i[0] + i[4]) + 5*max(1, i[1] + i[5]) + 2*max(0, i[2]+i[6]) + 2*(i[3]+i[7]))