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
    // fastio;

    int n;
    cin >> n;
    vvi v(n + 2, vi(n + 2, 0));
    vector<vector<array<int, 3>>> dp(n + 2, vector<array<int, 3>>(n + 2, array<int, 3>({ 0, 0, 0 })));
    f1(i, n) {
        f1(j, n) cin >> v[i][j];
    }

    dp[1][2] = { 0, 1, 1 };
    if (v[1][3])
        v[n][n] = 1;
    if (v[2][3] | v[2][2])
        dp[1][2] = { 0, 0, 1 };

    if (v[n][n]) {
        cout << 0;
        return 0;
    }

    f1(i, n) {
        f1(j, n) {
            if (v[i][j]) continue;
            if (!v[i + 1][j])
                dp[i][j][0] += dp[i - 1][j - 1][1] + dp[i - 1][j][0];
            if (!v[i][j + 1])
                dp[i][j][2] += dp[i][j - 1][2] + dp[i - 1][j - 1][1];
            if (!v[i][j + 1] && !v[i + 1][j + 1] && !v[i + 1][j])
                dp[i][j][1] += dp[i][j - 1][2] + dp[i - 1][j - 1][1] + dp[i - 1][j][0];
        }
    }

    cout << (v[n][n - 1] ? 0 : dp[n][n - 1][2]) + (v[n - 1][n - 1] ? 0 : dp[n - 1][n - 1][1]) + (v[n - 1][n] ? 0 : dp[n - 1][n][0]);
    return 0;
}