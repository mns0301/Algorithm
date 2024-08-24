#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct dij {
	long long distance;
	int target;
	int pass;

	bool operator<(const dij& i) const {
		return distance > i.distance;
	}
}dijk;

void dijkstra(vector<vector<pair<int,int>>> v, vector<vector<long long>>& dis, int k) {
	priority_queue<dijk> q;
	q.push({ 0, 1, 0 });
	dis[0][1] = 0;

	while (!q.empty()) {
		long long cost = q.top().distance;
		int pos = q.top().target;
		int road = q.top().pass;
		q.pop();
		if (road > k) continue;
		if (dis[road][pos] < cost) continue;

		for (int i = 0; i < v[pos].size(); i++) {
			long long sum_cost = cost + v[pos][i].second;
			if (road + 1 <= k && cost < dis[road + 1][v[pos][i].first]) {
				dis[road + 1][v[pos][i].first] = cost;
				q.push({ cost, v[pos][i].first, road + 1 });
			}
			if (sum_cost < dis[road][v[pos][i].first]) {
				dis[road][v[pos][i].first] = sum_cost;
				q.push({ sum_cost, v[pos][i].first, road });
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
	vector<vector<long long>> dis(k+1, vector<long long>(n+1, (long long)1e16));

	int t1, t2, t3;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		v[t1].push_back({ t2, t3 });
		v[t2].push_back({ t1, t3 });
	}

	dijkstra(v, dis, k);
	
	long long min = (long long)1e16;

	for (int i = 0; i <= k; i++) {
		if (dis[i][n] < min) min = dis[i][n];
	}

	cout << min;
	return 0;
}