n = int(input())
for i in range(n) :
    print("* " * (n//2) + ("*" if n%2 == 1 else ""))
    print(" *" * (n//2))