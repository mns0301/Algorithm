n = int(input())%8
print(1 if (n == 1) else 2 if (n in [0, 2]) else 3 if (n in [3, 7]) else 4 if (n in [4, 6]) else 5)