n,a,b = map(int, input().split())
if (n > b) :
    b = 10000000
print("Bus" if a < b else "Subway" if a > b else "Anything")