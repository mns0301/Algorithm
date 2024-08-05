#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) v.push_back(i + 1);
	int x, y;
	auto s = v.begin();
	auto e = v.end();
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		s = lower_bound(v.begin(), v.end(), x);
		e = lower_bound(v.begin(), v.end(), y);
		v.erase(s, e);
	}

	cout << v.size();

	return 0;
}