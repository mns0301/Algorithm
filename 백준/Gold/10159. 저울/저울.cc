#include <iostream>
#include <vector>
using namespace std;
#define f(i,n) for(int i=1;i<=n;i++)
int n,m,a,b,c;vector<vector<int>>v(101,vector<int>(101));main(){cin>>n>>m;f(i,m)cin>>a>>b,v[a][b]=2,v[b][a]=1;f(k,n){f(i,n){f(j,n){if(v[i][k]==2&&v[k][j]==2)v[i][j]=2,v[j][i]=1;}}}f(i,n){c=n;f(j,n){if(v[i][j])c--;}cout<<--c<<"\n";}}