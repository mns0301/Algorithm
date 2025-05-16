t = int(input())
for _ in range(t):
    n = int(input())
    for i in range(0, 21) :
        if n % 2 :
            print(i, end= " ")
        n //= 2
    print()