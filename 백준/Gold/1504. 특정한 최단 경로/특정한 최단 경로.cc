#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> v, vector<int> dis, int start, int end) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, start });
	dis[start] = 0;

	while (!q.empty()) {
		int cost = -q.top().first;
		int pos = q.top().second;
		q.pop();

		if (dis[pos] < cost) continue;

		for (int i = 0; i < v[pos].size(); i++) {
			int sum_cost = cost + v[pos][i].first;

			if (sum_cost < dis[v[pos][i].second]) {
				dis[v[pos][i].second] = sum_cost;
				q.push({ -sum_cost, v[pos][i].second });
			}
		}
	}
	return dis[end];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, e;
	cin >> n >> e;
	int t1, t2, t3;
	vector<vector<pair<int, int>>> v(n + 1);
	vector<int> dis(n + 1, 1e9);

	for (int i = 0; i < e; i++) {
		cin >> t1 >> t2 >> t3;
		v[t1].push_back({ t3, t2 });
		v[t2].push_back({ t3, t1 });
	}

	int v1, v2;
	cin >> v1 >> v2;

	int sum1 = dijkstra(v, dis, 1, v1) + dijkstra(v, dis, v1, v2) + dijkstra(v, dis, v2, n);
	int sum2 = dijkstra(v, dis, 1, v2) + dijkstra(v, dis, v2, v1) + dijkstra(v, dis, v1, n);

	if (sum1 > sum2 && sum2 < 1e9 && sum2 > 0) cout << sum2;
	else if (sum1 < 1e9 && sum1 > 0) cout << sum1;
	else cout << -1;

	return 0;
}