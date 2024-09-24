#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 1e9));
	for (int i = 1; i < n; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		v[t1][t2] = t3;
		v[t2][t1] = t3;
		v[i][i] = 0;
	}
	v[n][n] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		cout << v[t1][t2] << "\n";
	}

	return 0;
}