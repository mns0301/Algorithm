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
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 1e9));
	int t1, t2, t3;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		if (v[t1][t2] > t3) v[t1][t2] = t3;
	}

	for (int i = 0; i <= n; i++) v[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = min(v[i][k] + v[k][j], v[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == 1e9) cout << 0 << " ";
			else cout << v[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}