#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& v, int s, int e) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, s });
	vector<int> dist(v.size(), 1e9);
	dist[s] = 0;

	while (!q.empty()) {
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();
		
		if (dist[cur] < cost) continue;
		dist[cur] = cost;
		
		for (int i = 0; i < v[cur].size(); i++) {
			int sum = cost + v[cur][i].second;
			if (dist[v[cur][i].first] > sum) {
				dist[v[cur][i].first] = sum;
				q.push({ -sum, v[cur][i].first });
			}
		}
	}

	return dist[e];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);
	int t1, t2, t3;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		v[t1].push_back({ t2, t3 });
	}
	int s, e;
	cin >> s >> e;

	cout << dijkstra(v, s, e);

	return 0;
}