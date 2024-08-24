#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dijkstra(int field[501][501], vector<vector<int>> dis) {
	priority_queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {0, 1} });
	q.push({ 0, {1, 0} });

	while (!q.empty()) {
		pair<int, int> pos = q.top().second;
		int cost = -q.top().first;
		q.pop();
		//cout << pos.first << pos.second << q.size() << "\n";
		if (pos.first < 0 || pos.second < 0 || pos.first > 500 || pos.second > 500) continue;
		if (dis[pos.second][pos.first] < cost) continue;
		if (field[pos.second][pos.first] == 2) continue;
		if (field[pos.second][pos.first] == 1) cost++;

		if (cost < dis[pos.second][pos.first]) {
			dis[pos.second][pos.first] = cost;
			q.push({ -cost, {pos.first + 1, pos.second} });
			q.push({ -cost, {pos.first, pos.second + 1} });
			q.push({ -cost, {pos.first - 1, pos.second} });
			q.push({ -cost, {pos.first, pos.second - 1} });
		}
		//if (pos.first == 500 && pos.second == 500) return dis[500][500];
	}

	return dis[500][500];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int field[501][501] = { 0 };
	int n;
	int x1, y1, x2, y2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = y1; i <= y2; i++) {
			for (int j = x1; j <= x2; j++) field[i][j] = 1;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = y1; i <= y2; i++) {
			for (int j = x1; j <= x2; j++) field[i][j] = 2;
		}
	}
	vector<vector<int>> dis(501, vector<int>(501, 1e6));

	int result = dijkstra(field, dis);

	if (0 <= result && result < 1e6) cout << result;
	else cout << -1;

	return 0;
}