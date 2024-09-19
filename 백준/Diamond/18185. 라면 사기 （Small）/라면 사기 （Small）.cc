#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, cnt, ans = 0;
	cin >> n;
	vector<int> v(n + 2, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n; i++) {
		if (v[i + 1] > v[i + 2]) {
			cnt = min(v[i], v[i + 1] - v[i + 2]);
			ans += cnt * 5;
			v[i] -= cnt;
			v[i + 1] -= cnt;

			cnt = min(v[i], v[i + 2]);
		}
		else cnt = min(v[i], v[i + 1]);

		ans += cnt * 7;
		v[i] -= cnt;
		v[i + 1] -= cnt;
		v[i + 2] -= cnt;
		ans += v[i] * 3;
	}
	cout << ans;

	return 0;
}