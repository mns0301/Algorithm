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
	vector<int> an(n, 0);
	for (int i = 0; i < n; i++) cin >> an[i];
	vector<int> dp(n, 1);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (an[j] > an[i]) dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > ans) ans = dp[i];
	}

	cout << ans;

	return 0;
}