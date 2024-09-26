#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v[i].first; j++) dp[i][j] = dp[i - 1][j];
        for (int j = v[i].first; j <= k; j++) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
    }

    cout << dp[n][k];

    return 0;
}