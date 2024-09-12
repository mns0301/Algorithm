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
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	double m = 0;
	vector<int> ans(n, 0);
	int max = 0;
	double temp = 0;
	for (int i = 0; i < n; i++) {
		m = 2e9;
		for (int j = i - 1; j >= 0; j--) {
			temp = (double)(v[j] - v[i]) / (j - i);
			if (m > temp) {
				ans[i]++;
				m = temp;
			}
		}

		m = -2e9;
		for (int j = i + 1; j < n; j++) {
			temp = (double)(v[j] - v[i]) / (j - i);
			if (m < temp) {
				ans[i]++;
				m = temp;
			}
		}
		if (max < ans[i]) max = ans[i];
	}

	cout << max;

	return 0;
}