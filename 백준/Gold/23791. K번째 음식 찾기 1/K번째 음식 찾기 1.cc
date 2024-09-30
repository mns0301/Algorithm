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
	vector<int> f1(n + 1, 0);
	vector<int> f2(n + 1, 0);

	for (int i = 0; i < n; i++) cin >> f1[i];
	for (int i = 0; i < n; i++) cin >> f2[i];

	int q;
	cin >> q;
	while (q--) {
		int i, j, k;
		cin >> i >> j >> k;	
		long long left = 0, right = 1e18;
		int ac, bc;
		while (left + 1 < right) {
			long long mid = (left + right) / 2;
			ac = lower_bound(f1.begin(), f1.begin() + i, mid) - f1.begin();
			bc = lower_bound(f2.begin(), f2.begin() + j, mid) - f2.begin();

			if (ac + bc > k) right = mid;
			else if (ac + bc == k) break;
			else left = mid;
		}
		pair<int, int> p = { 0, -1 };
		int ans = -1;
		if (ac - 1 >= 0 && f1[ac - 1] > ans) {
			ans = f1[ac - 1];
			p = { 1, ac };
		}
		if (bc - 1 >= 0 && f2[bc - 1] > ans) {
			ans = f2[bc - 1];
			p = { 2, bc };
		}

		cout << p.first << " " << p.second << "\n";

	}

	return 0;
}