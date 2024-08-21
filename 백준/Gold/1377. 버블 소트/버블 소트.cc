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
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second - i > max) max = v[i].second - i;
	}

	cout << max + 1;

	return 0;
}	