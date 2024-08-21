#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(vector<string> v, int ans[100][100], int n, int x, int y, char c, int cnt) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == n || y == n || x < 0 || y < 0) continue;
		if (ans[y][x] != 0) continue;
		if (v[y][x] != c) continue;

		ans[y][x] = cnt;
		q.push({ x - 1, y });
		q.push({ x + 1, y });
		q.push({ x, y - 1 });
		q.push({ x, y + 1 });
	}
}

void BFS2(vector<string> v, int ans[100][100], int n, int x, int y, char c, int cnt) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	if (c == 'R') c = 'G';

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == n || y == n || x < 0 || y < 0) continue;
		if (ans[y][x] != 0) continue;
		if ((c == 'B' && v[y][x] == 'B') || (c == 'G' && (v[y][x] == 'G' || v[y][x] == 'R'))) {
			ans[y][x] = cnt;
			q.push({ x - 1, y });
			q.push({ x + 1, y });
			q.push({ x, y - 1 });
			q.push({ x, y + 1 });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int ans[100][100] = { 0 };
	int ans2[100][100] = { 0 };
	int cnt1 = 0;
	int cnt2 = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] == 0) BFS(v, ans, n, j, i, v[i][j], ++cnt1);
			if (ans2[i][j] == 0) BFS2(v, ans2, n, j, i, v[i][j], ++cnt2);
		}
	}

	cout << cnt1 << " " << cnt2;

	return 0;
}