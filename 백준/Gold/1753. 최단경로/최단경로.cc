#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& v, vector<int>& dist, int k) {
	priority_queue<pair<int, int>> pq;
	pq.push({0, k});
	dist[k] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		
		if (dist[pos] < cost) continue;

		for (int i = 0; i < v[pos].size(); i++) {
			int sum_cost = cost + v[pos][i].second;
			if (sum_cost < dist[v[pos][i].first]) {
				dist[v[pos][i].first] = sum_cost;
				pq.push({ -sum_cost, v[pos][i].first });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> v(n + 1);
	int t1, t2, t3;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		v[t1].push_back({ t2, t3 });
	}
	vector<int> dist(n + 1, 1e6);

	dijkstra(v, dist, k);

	for (int i = 1; i <= n; i++) {
		if (dist[i] == 1e6) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}