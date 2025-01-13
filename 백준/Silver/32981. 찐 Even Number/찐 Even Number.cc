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

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

ll POW(ll n, ll p)
{
    if (p == 1)
        return n;
    if (p == 0)
        return 1;

    if (p & 1)
        return (POW(n, p - 1) * n) % 1000000007;
    else
    {
        ll tmp = POW(n, p / 2) % 1000000007;

        return (tmp * tmp) % 1000000007;
    }
}

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
        cout << 5 << '\n';

    else
    {
        cout << (4 * POW(5, n - 1)) % 1000000007 << '\n';
    }
}

int main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}