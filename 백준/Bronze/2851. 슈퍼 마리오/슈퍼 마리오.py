s = 0
for i in range(10) :
    t = int(input())
    if (abs(100-s) >= abs(100-s-t)) :
        s += t
    else :
        break
print(s)