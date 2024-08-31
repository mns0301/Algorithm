#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dijkstra(vector<string>& v, int n, int m) {
	priority_queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {-1, 0}, {0, 0}});
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(m, 1e9)));

	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int cost = -q.top().first.first;
		int des = q.top().first.second;
		q.pop();

		if (x == m || y == n || x < 0 || y < 0) continue;
		if (dp[des][y][x] < cost) continue;
		if (des == 1 && v[y][x] == '1') continue;
		else if (des == 0 && v[y][x] == '1') des = 1;

		dp[des][y][x] = cost++;
		if (!(x == m || y + 1 == n || x < 0 || y < 0) && (dp[des][y + 1][x] == 1e9)) {
			q.push({ {-cost, des}, {x, y + 1} });
			dp[des][y + 1][x] = cost;
		}
		if (!(x == m || y == n || x < 0 || y < 1) && (dp[des][y - 1][x] == 1e9)) {
			q.push({ {-cost, des}, {x, y - 1} });
			dp[des][y - 1][x] = cost;
		}
		if (!(x + 1 == m || y == n || x < 0 || y < 0) && (dp[des][y][x + 1] == 1e9)) {
			q.push({ {-cost, des}, {x + 1, y} });
			dp[des][y][x + 1] = cost;
		}
		if (!(x == m || y == n || x < 1 || y < 0) && (dp[des][y][x - 1] == 1e9)) {
			q.push({ {-cost, des}, {x - 1, y} });
			dp[des][y][x - 1] = cost;
		}
	}

	return min(dp[0][n - 1][m - 1], dp[1][n - 1][m - 1]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	int ans = dijkstra(v, n, m);
	if (ans == 1e9) cout << -1;
	else cout << ans;

	return 0;
}