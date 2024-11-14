#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int cnt = 0;

	int* coins = new int[n];
	for (int i = 0; i < n; i++) cin >> coins[i];

	for (int i = n - 1; i > -1; i--) {
		cnt += k / coins[i];
		k %= coins[i];
	}

	cout << cnt;


	return 0;
}
