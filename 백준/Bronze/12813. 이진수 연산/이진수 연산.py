a = input()
b = input()
for i in range(len(a)) :
    print("1" if a[i] == b[i] == "1" else "0", end = "")
print()
for i in range(len(a)) :
    print("1" if a[i] == "1" or b[i] == "1" else "0", end = "")
print()
for i in range(len(a)) :
    print("1" if a[i] != b[i] else "0", end = "")
print()
for i in range(len(a)) :
    print("1" if a[i] == "0" else "0", end = "")
print()
for i in range(len(a)) :
    print("1" if b[i] == "0" else "0", end = "")
print()
#A & B, A | B, A ^ B, ~A, ~B