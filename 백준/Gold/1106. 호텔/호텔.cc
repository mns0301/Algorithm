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

int main() {
	fastio;

    int c, n;
    cin >> c >> n;
    vpii v(n);
    f(i, n) cin >> v[i].first >> v[i].second;
    vi dp(c + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        auto [cost, peo] = v[i];
        dp[peo] = min(dp[peo], cost);
    }
    for (int i = 0; i < n; i++) {
        auto [cost, peo] = v[i];
        for (int gap = 0; gap < peo; gap++) {
            // dp[gap+peo] = min(dp[gap+peo], cost);
            int j = peo + gap;
            while (true) {
                dp[min(j, c)] = min(dp[min(j, c)], dp[min(j - peo, c)] + cost);
                // cout << "peo= " << j << " cost=" << dp[j] << " \n";
                if (j >= c)
                    break;
                j += peo;
            }

            // for (int j = peo + gap; j <= c; j += peo) {
            //     dp[j] = min(dp[j], dp[j - peo] + cost);
            //     cout << "peo= " << j << " cost=" << dp[j] << " \n";
            // }
        }
    }

    cout << dp[c];
    return 0;
}