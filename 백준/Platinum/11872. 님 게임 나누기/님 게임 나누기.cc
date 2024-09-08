#include<iostream>
using namespace std;int n,t,a;main(){cin>>n;while(n--){cin>>t;if(t%4==3)a^=t+1;else if(t%4==0)a^=t-1;else a^=t;}if(a)cout<<"koosaga";else cout<<"cubelover";}