#include <algorithm>
#include <iostream>
#include <vector>
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

    ll n, s;
    cin >> n >> s;
    vl v(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        v[i] = v[i - 1] + t;
    }

    ll start = 0, end = 0;
    ll sz = 1'000'000;
    while (start <= end && end <= n) {
        ll temp = v[end] - v[start];
        if (temp < s) end++;
		else {
            sz = min(sz, end - start);
            start++;
        }
    }
    if (sz == 1'000'000) cout << 0;
    else cout << sz;

    return 0;
}