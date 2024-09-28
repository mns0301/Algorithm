#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<bool> dp(2 * n, 0);
    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int pos = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (dp[pos]) continue;
        dp[pos] = 1;
        if (cost > k || pos == n) break;

        if (pos > n) continue;
        if (!dp[pos + 1]) q.push({ pos + 1, cost + 1 });
        if (!dp[pos + pos / 2]) q.push({ pos + pos / 2, cost + 1 });
    }

    if (dp[n]) cout << "minigimbob";
    else cout << "water";
  
    return 0;
}