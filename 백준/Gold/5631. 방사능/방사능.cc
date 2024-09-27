#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long t = 1;
	while (1) {
		long long n;
		cin >> n;
		if (n == 0) break;

		vector<pair<long long, long long>> pos(n);
		for (int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;

		long long ax, ay, bx, by, q;
		cin >> ax >> ay >> bx >> by >> q;

		vector<long long> dis_a(n);
		vector<long long> dis_b(n);
		for (int i = 0; i < n; i++) {
			dis_a[i] = (ax - pos[i].first) * (ax - pos[i].first) + (ay - pos[i].second) * (ay - pos[i].second);
			dis_b[i] = (bx - pos[i].first) * (bx - pos[i].first) + (by - pos[i].second) * (by - pos[i].second);
		}

		vector<pair<long long, long long>> r(q);
		for (int i = 0; i < q; i++) cin >> r[i].first >> r[i].second;


		sort(dis_a.begin(), dis_a.end());
		sort(dis_b.begin(), dis_b.end());

		cout << "Case " << t << ":\n";
		for (int i = 0; i < q; i++) {
			long long x, y;
			x = upper_bound(dis_a.begin(), dis_a.end(), (r[i].first * r[i].first)) - dis_a.begin();
			y = upper_bound(dis_b.begin(), dis_b.end(), (r[i].second * r[i].second)) - dis_b.begin();
			if (n < x + y) cout << "0\n";
			else cout << n - x - y << "\n";
		}
		t++;
	}

	return 0;
}