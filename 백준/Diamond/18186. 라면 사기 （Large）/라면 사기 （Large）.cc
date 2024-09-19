#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, b, c, cnt, ans = 0;
	cin >> n >> b >> c;
	vector<long long> v(n + 2, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	if (b < c) {
		for (int i = 0; i < n; i++) ans += b * v[i];
	}
	else {
		for (int i = 0; i < n; i++) {
			if (v[i + 1] > v[i + 2]) {
				cnt = min(v[i], v[i + 1] - v[i + 2]);
				ans += cnt * (b + c);
				v[i] -= cnt;
				v[i + 1] -= cnt;

				cnt = min(v[i], v[i + 2]);
			}
			else cnt = min(v[i], v[i + 1]);

			ans += cnt * (b + 2 * c);
			v[i] -= cnt;
			v[i + 1] -= cnt;
			v[i + 2] -= cnt;
			ans += v[i] * b;
		}
	}
	cout << ans;

	return 0;
}