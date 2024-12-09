li = []
for i in range(5) :
    li.append(int(input()))
    if (li[i] < 40) :
        li[i] = 40
print(int(sum(li) / 5))