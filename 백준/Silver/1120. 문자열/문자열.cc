#include<iostream>
std::string a,b;int main(){std::cin>>a>>b;int s=a.size(),d=b.size()-s,m=99,t,i,j;for(i=0;i<=d;i++){t=0;for(j=0;j<s;j++){if(a[j]!=b[i+j])t++;}if(t<m)m=t;}std::cout<<m;}