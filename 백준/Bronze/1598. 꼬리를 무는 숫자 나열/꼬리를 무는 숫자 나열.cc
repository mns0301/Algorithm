#include <stdio.h>
#include <math.h>
int main(){int n,m;scanf("%d%d",&n,&m);printf("%d",abs((n-1)/4-(m-1)/4)+abs((n-1)%4-(m-1)%4));}