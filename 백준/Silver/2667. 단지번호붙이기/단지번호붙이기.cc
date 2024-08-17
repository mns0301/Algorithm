#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int BFS(vector<vector<char>>& v, int x, int y, int n) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x < 0 || y < 0 || x == n || y == n) continue;
		if (v[y][x] == '1') {
			cnt++;
			v[y][x] = '0';
			q.push({ x - 1, y });
			q.push({ x, y - 1 });
			q.push({ x + 1, y });
			q.push({ x, y + 1 });
		}
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> ans;
	vector<vector<char>> v(n, vector<char>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (v[y][x] == '1') {
				ans.push_back(BFS(v, x, y, n));
			}
		}
	}

	sort(ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

	return 0;
}