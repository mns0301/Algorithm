from math import factorial as f
n,a,b,c=map(int, input().split())
print((int)(f(n)/(f(a)*f(b)*f(c))))