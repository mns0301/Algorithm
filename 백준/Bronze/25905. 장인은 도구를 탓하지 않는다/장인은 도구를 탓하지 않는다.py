li = []
x = 1
for i in range(10) :
    li.append(float(input()))
li.sort()
for i in range(1, 10) :
    x *= li[i]*10/i
print(x)