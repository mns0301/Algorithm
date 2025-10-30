#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int dy8[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx8[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy4[4] = { -1, 0, 1, 0 };
int dx4[4] = { 0, 1, 0, -1 };

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
	fastio;

    int n, k;
    cin >> n >> k;
    vi v(n);
    f(i, n) cin >> v[i];
    int x = gcd(n, k);

    vvi y(x);
    for (int i = 0; i < n; i++) 
        y[i % x].push_back(v[i]);

    for (int i = 0; i < x; i++) 
        sort(y[i].begin(), y[i].end());

    int pre = y[0][0];
    for (int i = 1; i < n; i++) {
		if (y[i%x][i/x] >= pre)
            pre = y[i % x][i / x];
		else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}