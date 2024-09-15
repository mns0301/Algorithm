#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, t1, t2, t3;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 1e9));
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		v[t1][t2] = t3;
	}
	for (int i = 0; i <= n; i++) v[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}

	int k;
	cin >> k;
	vector<int> peo(k, 0);
	for (int i = 0; i < k; i++) cin >> peo[i];
	int min = 1e9;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j < k; j++) {
			if (max < v[peo[j]][i] + v[i][peo[j]]) max = v[peo[j]][i] + v[i][peo[j]];
		}
		if (max < min) {
			min = max;
			ans.erase(ans.begin(), ans.end());
			ans.push_back(i);
		}
		else if (max == min) ans.push_back(i);
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	return 0;
}