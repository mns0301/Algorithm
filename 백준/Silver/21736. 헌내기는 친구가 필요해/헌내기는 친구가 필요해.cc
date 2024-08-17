#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int BFS(vector<vector<char>>& v, int x, int y, int n, int m) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (x < 0 || y < 0 || x == m || y == n) continue;
		if (v[y][x] == 'X') continue;
		if (v[y][x] == 'P') cnt++;

		v[y][x] = 'X';
		q.push({ x - 1, y });
		q.push({ x, y - 1 });
		q.push({ x + 1, y });
		q.push({ x, y + 1 });
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int t;
	int x = 0, y = 0;
	vector<vector<char>> v(n, vector<char>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'I') {
				y = i;
				x = j;
				v[i][j] = 'O';
			}
		}
	}

	t = BFS(v, x, y, n, m);
	if (t == 0) cout << "TT";
	else cout << t;

	return 0;
}