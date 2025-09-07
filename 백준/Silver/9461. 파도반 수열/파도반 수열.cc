#import<iostream>
long d[101]={1,1,1},i;main(){for(i;i<97;)d[i+2]=d[i++]+d[i];for(std::cin>>i;std::cin>>i;)printf("%ld ",d[i-1]);}