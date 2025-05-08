#include <iostream>
#include <algorithm>
using namespace std;

int find(int* dp, int n) {
	if (dp[n] != 0) return dp[n];
	else {
		if (n % 6 == 0) dp[n] = (find(dp, n / 3) < find(dp, n / 2) ? dp[n / 3] : dp[n / 2]) + 1;
		else if (n % 3 == 0) dp[n] = (find(dp, n / 3) < find(dp, n - 1) ? dp[n / 3] : dp[n - 1]) + 1;
		else if (n % 2 == 0) dp[n] = (find(dp, n / 2) < find(dp, n - 1) ? dp[n / 2] : dp[n - 1]) + 1;
		else dp[n] = find(dp, n - 1) + 1;
		return dp[n];
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int* dp = new int[n + 1]();
	dp[1] = 0;
	if (n > 1) dp[2] = 1;
	if (n > 2) dp[3] = 1;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	find(dp, n);
	cout << dp[n];

	delete[] dp;
	return 0;
}