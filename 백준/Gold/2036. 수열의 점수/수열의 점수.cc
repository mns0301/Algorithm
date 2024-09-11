#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<long long> pl, mi;
	int zero = 0;
	int one = 0;

	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 0) zero++;
		else if (t == 1) one++;
		else if (t > 0) pl.push_back(t);
		else mi.push_back(t);
	}
	sort(pl.begin(), pl.end(), greater<int>());
	sort(mi.begin(), mi.end());
	long long ans = 0;

	for (int i = 1; i < pl.size(); i += 2) {
		ans += pl[i - 1] * pl[i];
	}
	if (pl.size() % 2 == 1) ans += pl[pl.size() - 1];
	ans += one;
	for (int i = 1; i < mi.size(); i += 2) {
		ans += mi[i - 1] * mi[i];
	}
	if (mi.size() % 2 == 1 && zero == 0) ans += mi[mi.size() - 1];

	cout << ans;

	return 0;
}