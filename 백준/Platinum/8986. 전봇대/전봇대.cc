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

int n;
vl v(100000);

ll fun(ll itv) {
    ll w = 0;
    for (int i = 1; i < n; i++) {
        w += abs(v[i] - itv * i);
    }
    return w;
}

int main() {
	fastio;

    cin >> n;
    f(i, n) cin >> v[i];
    ll l = 0, r = 1e9;
    while (l + 1 < r) 
    {
        ll mid = (l + r) / 2;
        ll f, g, h;
        f = fun(mid - 1);
        g = fun(mid);
        h = fun(mid + 1);
        if (f < g && g < h)
            r = mid;
        else if (f > g && g > h)
            l = mid;
        else {
            l = mid;
            r = mid;
        }
    }
    cout << fun(l);

    return 0;
}