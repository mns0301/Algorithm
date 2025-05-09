while (1) :
    a,b=map(int, input().split())
    if(a==b and b==0) :
        break
    print(2*min(a,b) - max(a,b))