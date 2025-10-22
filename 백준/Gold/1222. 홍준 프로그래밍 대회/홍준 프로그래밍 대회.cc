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

#define N 2000001l
vl p(2000001, 0);
vl is_pri(2000001, 1);
vi primes;
void pri() {
    is_pri[0] = 0;
    is_pri[1] = 1;
    for (ll i = 2; i < N; i++) {
        if (p[i]) continue;
        p[i] = i;
        primes.push_back(i);
        for (ll j = i * i; j < N; j += i) {
            p[j] = i;
            is_pri[j] = 0;
        }
    }
}

int main() {
	fastio;

    // pri();

    int n;
    cin >> n;
    // vi v(n);
    vl table(N, 0);
	f(i, n) {
        ll t;
        cin >> t;
        table[t]++;
    }
    ll ans = 0;
    for (ll i = 1; i < N; i++) {
        ll cnt = 0;
        for (ll j = i; j < N; j += i) {
            cnt += table[j];
        }
		if (cnt > 1)
	        ans = max(ans, cnt*i);
    }
    cout << ans;

    return 0;
}