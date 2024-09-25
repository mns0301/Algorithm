hms = input().split()
t = int(input())
s = int(hms[2]) + t
m = int(hms[1]) + s // 60
h = int(hms[0]) + m // 60
print(h%24, m%60, s%60)