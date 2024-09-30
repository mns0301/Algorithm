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
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];

	int l = 1, r = 1e9;
	while (l + 1 < r) {
		int m = (l + r) / 2;

		int cnt = 0;
		bool suc = 0;
		for (int i = 0; i < n; i++) {
			if (h[i] >= m) cnt++;
			else cnt = 0;

			if (cnt >= m) {
				suc = 1;
				break;
			}
		}
		if (suc == 1) l = m;
		else r = m;
	}

	cout << l;

	return 0;
}