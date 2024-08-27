#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int root(vector<int>& g_n, int x) {
	if (g_n[x] == x) return x;
	else return g_n[x] = root(g_n, g_n[x]);
}

void Union(vector<int>& g_n, int x, int y) {
	x = root(g_n, g_n[x]);
	y = root(g_n, g_n[y]);
	if (x < y) g_n[y] = x;
	else g_n[x] = y;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, t;
	cin >> n >> m >> t;
	vector<int> g_n(n + 1, 0);
	for (int i = 0; i <= n; i++) g_n[i] = i;
	vector<int> t_n(t, 0);
	for (int i = 0; i < t; i++) cin >> t_n[i];

	vector<vector<int>> temp(m);
	for (int i = 0; i < m; i++) {
		int t1;
		cin >> t1;
		temp[i] = vector<int>(t1, 0);

		for (int j = 0; j < t1; j++) cin >> temp[i][j];
		for (int j = 0; j < t1; j++) g_n[temp[i][j]] = root(g_n, g_n[temp[i][j]]);
		for (int j = 1; j < t1; j++) Union(g_n, g_n[temp[i][0]], g_n[temp[i][j]]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < t; j++) {
			if (root(g_n, g_n[i]) == root(g_n, g_n[t_n[j]])) g_n[root(g_n, g_n[i])] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int j = 0;
		for (j; j < temp[i].size(); j++) {
			if (root(g_n, temp[i][j]) == 0) break;
		}
		if (j == temp[i].size()) cnt++;
	}

	cout << cnt;

	return 0;
}