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
	vector<int> v(20000001, 0);

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v[t + 10000000]++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		cout << v[t + 10000000] << " ";
	}

	return 0;
}