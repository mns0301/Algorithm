#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Small(vector<int> an, int n) {
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (an[j] > an[i]) dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	return dp;
}

vector<int> Large(vector<int> an, int n) {
	vector<int> dp(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (an[j] > an[i]) dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	return dp;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> an(n, 0);
	for (int i = 0; i < n; i++) cin >> an[i];
	vector<int> v(n, 0);
	vector<int> small(Small(an, n));
	vector<int> large(Large(an, n));
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int temp = small[i] + large[i] + 1;
		if (temp > ans) ans = temp;
	}

	cout << ans;

	return 0;
}