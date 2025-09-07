#include<iostream>
long d[100]={1,1,1},t,n;main(){for(t;t<97;)d[t+2]=d[t++]+d[t];std::cin>>t;while(t--){std::cin>>n;std::cout<<d[n-1]<<"\n";}}