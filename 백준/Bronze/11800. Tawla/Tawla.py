li1 = [0, "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"]
li2 = [0, "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"]
t = int(input())
for i in range(1, t+1) :
    a,b = map(int, input().split())
    s = li2[a] if a == b else "Sheesh Beesh" if (a==5 and b==6) or (a==6 and b==5) else li1[max(a,b)] + " " + li1[min(a,b)]
    print("Case " + str(i) + ": " + s)