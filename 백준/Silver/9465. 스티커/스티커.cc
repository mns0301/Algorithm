#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> d1(n, 0);
		vector<int> d2(n, 0);
		vector<int> data1(n, 0);
		vector<int> data2(n, 0);
		for (int i = 0; i < n; i++) cin >> data1[i];
		for (int i = 0; i < n; i++) cin >> data2[i];
		d1[0] = data1[0];
		d2[0] = data2[0];

		if (n > 1) {
			d1[1] = data2[0] + data1[1];
			d2[1] = data1[0] + data2[1];
		}

		for (int i = 2; i < n; i++) {
			d1[i] = max(d2[i - 1], d2[i - 2]) + data1[i];
			d2[i] = max(d1[i - 1], d1[i - 2]) + data2[i];
		}
		cout << max(d1[n-1], d2[n-1]) << "\n";
	}

	return 0;
}