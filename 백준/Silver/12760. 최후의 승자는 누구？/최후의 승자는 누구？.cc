#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(m, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end(), greater<int>());
	vector<int> score(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int max = 0;
		for (int j = 1; j <= n; j++) {
			if (max < v[j][i]) max = v[j][i];
		}
		for (int j = 1; j <= n; j++) {
			if (v[j][i] == max) score[j]++;
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < score[i]) max = score[i];
	}
	for (int i = 1; i <= n; i++) {
		if (max == score[i]) cout << i << " ";
	}

	return 0;
}