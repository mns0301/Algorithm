#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct di3 {
	int x;
	int y;
	int z;
} d3;

int BFS(vector<vector<vector<int>>>& v, queue<d3>& que, int x, int y, int z, int m, int n, int h) {
	if (z < 0 || z == h || y < 0 || y == n || x < 0 || x == m) return 0;
	if (v[z][y][x] == 0) {
		v[z][y][x] = 1;
		d3 pos = { x, y, z };
		que.push(pos);
		return 1;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n, h;
	cin >> m >> n >> h;
	vector<vector<vector<int>>> v(h, vector<vector<int>>(n, vector<int>(m, 0)));
	queue<d3> que;
	int changed = 0;
	int temp = 0;
	int day = -1;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> v[i][j][k];
				if (v[i][j][k] == 1) {
					que.push({k, j, i});
					changed++;
				}
			}
		}
	}

	int x = 0, y = 0, z = 0;
	int len = 0;
	while (!que.empty()) {
		temp = 0;
		len = que.size();
		for (int i = 0; i < len; i++) {
			x = que.front().x;
			y = que.front().y;
			z = que.front().z;
			que.pop();

			temp += BFS(v, que, x - 1, y, z, m, n, h);
			temp += BFS(v, que, x + 1, y, z, m, n, h);
			temp += BFS(v, que, x, y - 1, z, m, n, h);
			temp += BFS(v, que, x, y + 1, z, m, n, h);
			temp += BFS(v, que, x, y, z - 1, m, n, h);
			temp += BFS(v, que, x, y, z + 1, m, n, h);
		}
		changed = temp;
		day++;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (v[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << day;
	return 0;
}