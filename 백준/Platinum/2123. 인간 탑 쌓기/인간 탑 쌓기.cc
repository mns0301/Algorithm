#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
// #define int long long
#define ll long long
#define ld long double
#define pii pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define loop(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define foreach(i, v) for(auto i : v)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

int dy8[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dx8[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
int dy4[4] = { 0, 0, -1, 1 };
int dx4[4] = { -1, 1, 0, 0 };

bool comp(pii a, pii b) {
	if (a.first + a.second <= b.first + b.second)
        return 0;
    return 1;
}

int main() {
	fastio;

    int n;
    cin >> n;
    vpii v(n);
    f(i, n) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), comp);

    ll ans = -v[n - 1].second;
    for (int i = n - 1; i > 0; i--) {
        v[i-1].first += v[i].first;
        ans = max(ans, v[i].first - v[i-1].second);
        // cout << v[i].first - v[i - 1].second << "\n";
    }
    cout << ans;

    return 0;
}