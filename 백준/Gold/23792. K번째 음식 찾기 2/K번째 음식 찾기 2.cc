#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<long long> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	int q;
	cin >> q;

	while (q--) {
		int x, y, z, k;
		cin >> x >> y >> z >> k;
		int ca, cb, cc;
		long long l = 0, r = 1e18;
		long long mid = (l + r) / 2;
		
		while (l + 1 < r) {
			mid = (l + r) / 2;
			ca = lower_bound(a.begin(), a.begin() + x, mid) - a.begin();
			cb = lower_bound(b.begin(), b.begin() + y, mid) - b.begin();
			cc = lower_bound(c.begin(), c.begin() + z, mid) - c.begin();
			int cnt = ca + cb + cc;

			if (cnt > k) r = mid;
			else if (cnt == k) break;
			else l = mid;
		}

		pair<int, int> p = { 0, -1 };
		long long ans = -1;
		if (ca - 1 >= 0 && a[ca - 1] > ans) {
			ans = a[ca - 1];
			p = { 1, ca };
		}
		if (cb - 1 >= 0 && b[cb - 1] > ans) {
			ans = b[cb - 1];
			p = { 2, cb };
		}
		if (cc - 1 >= 0 && c[cc - 1] > ans) {
			ans = c[cc - 1];
			p = { 3, cc };
		}

		cout << p.first << " " << p.second << "\n";
	}

	
	return 0;
}