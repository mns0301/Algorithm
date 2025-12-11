#import<iostream>
int a,b,k;main(){for(std::cin>>a>>k>>b;std::cin>>a;a>b?b=a:b)if(b-a>k)break;std::cout<<(b-a>k?"NO":"YES");}