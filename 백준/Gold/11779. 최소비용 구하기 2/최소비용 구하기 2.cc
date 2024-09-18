#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, s, e;
vector<vector<pair<int, int>>> v(1001);
vector<int> dist(1001, 2e9);
vector<int> nodes(1001);

void dijkstra() {
	priority_queue<pair<int, int>> q;
	q.push({ 0, s });
	dist[s] = 0;

	while (!q.empty()) {
		int cost = -q.top().first;
		int pos = q.top().second;
		q.pop();

		if (dist[pos] < cost) continue;
		if (pos == e) break;

		for (int i = 0; i < v[pos].size(); i++) {
			int cost_temp = cost + v[pos][i].second;
			if (dist[v[pos][i].first] > cost_temp) {
				dist[v[pos][i].first] = cost_temp;
				nodes[v[pos][i].first] = pos;
				q.push({ -cost_temp, v[pos][i].first });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int t1, t2, t3;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		v[t1].push_back({ t2, t3 });
	}
	cin >> s >> e;

	dijkstra();

	cout << dist[e] << "\n";

	int i = e;
	vector<int> trace;
	while (i) {
		trace.push_back(i);
		i = nodes[i];
	}

	cout << trace.size() << "\n";
	for (int i = trace.size()-1; i >= 0; i--) cout << trace[i] << " ";

	return 0;
}