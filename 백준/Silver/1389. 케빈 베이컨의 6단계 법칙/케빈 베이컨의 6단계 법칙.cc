#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BFS(vector<vector<int>>& cost) {
	int n = cost.size();
	for (int k = 1; k < n; k++) {
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> cost(n + 1, vector<int>(n + 1, 1e9));
	int p1, p2;
	for (int i = 0; i <= n; i++) cost[i][i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		cost[p1][p2] = 1;
		cost[p2][p1] = 1;
	}

	BFS(cost);
	vector<int> kebin(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) kebin[i] += cost[i][j];
	}
	int min = 1;
	for (int i = 2; i <= n; i++) {
		if (kebin[min] > kebin[i]) min = i;
	}
	cout << min;

	return 0;
}