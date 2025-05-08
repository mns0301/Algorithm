#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= k) v.push_back(a);
    }
    vector<int> dp(k + 1, 10001);
    dp[0] = 0;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < v.size(); i++) {
        int cur = v[i];
        for (int j = cur; j <= k; j++) {
            dp[j] = min(dp[j], dp[j-cur] + 1);
        }
    }

    if (dp[k] == 10001) cout << -1;
    else cout << dp[k];

    return 0;
}