a,b,c,*d = map(int, open(0).read().split())
for t in d:
    print("NE" if t*t > b*b+c*c else "DA")