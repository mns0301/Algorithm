#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, m, temp;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		auto iter = lower_bound(v.begin(), v.end(), temp);
		if (iter != v.end() && *iter == temp) cout << "1 ";
		else cout << "0 ";
	}

	return 0;
}