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
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	long long m;
	cin >> m;

	long long l = 0, r = 1e9;
	long long temp = 0;
	long long c = 0;
	long long mid = (l + r) / 2;

	long long maxa = -1;
	for (int i = 0; i < n; i++) {
		temp += v[i];
		maxa = max(v[i], maxa);
	}
	if (temp <= m) {
		cout << maxa;
		return 0;
	}

	while (l + 1 < r) {
		temp = 0;
		mid = (l + r) / 2;

		for (int i = 0; i < n; i++) {
			if (mid > v[i]) temp += v[i];
			else temp += mid;
		}

		if (temp > m) r = mid;
		else l = mid;
	}

	cout << l;
	return 0;
}