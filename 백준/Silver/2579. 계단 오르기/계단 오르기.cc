#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n, 0);
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++) cin >> v[i];

	dp[0] = v[0];
	if (n > 1) dp[1] = v[1] + v[0];
	if (n > 2) dp[2] = max(v[1], v[0]) + v[2];
	for (int i = 3; i < n; i++) dp[i] = max(dp[i - 3] + v[i - 1], dp[i - 2]) + v[i];

	cout << dp[n - 1];

	return 0;
}