#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define f(i, n) for (int i = 0; i < n; i++)

int main(void) { 
	fastio;

    int n;
    cin >> n;
    int cost1 = 0, cost2 = 0;

	while (n--) {
        int t;
        cin >> t;

        cost1 += ceil((float)(t+1) / 30) * 10;
        cost2 += ceil((float)(t+1) / 60) * 15;
    }

    if (cost1 < cost2)
        cout << "Y " << cost1;
    else if (cost1 > cost2)
        cout << "M " << cost2;
	else
        cout << "Y M " << cost1;
}