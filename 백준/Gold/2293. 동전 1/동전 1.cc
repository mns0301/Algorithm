#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int coin : v) {
        for (int i = coin; i <= k; i++) dp[i] += dp[i - coin];
    }

    cout << dp[k];

    return 0;
}