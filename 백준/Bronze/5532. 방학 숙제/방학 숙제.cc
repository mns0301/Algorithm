#include <iostream>
main(){int l,a,b,c,d;std::cin>>l>>a>>b>>c>>d;int x=a%c?a/c+1:a/c,y=b%d?b/d+1:b/d;std::cout<<l-(x>y?x:y);}