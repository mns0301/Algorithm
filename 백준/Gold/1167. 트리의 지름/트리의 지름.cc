#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int mm = 0;
int BFS(vector<vector<pair<int, int>>>& v, vector<int>& visit, int s) {
	queue<int> q;
	q.push(s);
	vector<int> dist(visit.size(), 0);
	

	while (!q.empty()) {
		s = q.front(); q.pop();

		if (visit[s] == 1) continue;
		visit[s] = 1;
		for (int i = 0; i < v[s].size(); i++) {
			if (visit[v[s][i].first] != 0) continue;
			dist[v[s][i].first] = v[s][i].second + dist[s];
			q.push(v[s][i].first);
		}
	}
	int max = 1;
	for (int i = 2; i < dist.size(); i++) {
		if (dist[max] < dist[i]) max = i;
	}
	mm = dist[max];
	return max;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> v(n + 1);
	vector<int> visit(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int t1, t2, t3;
		cin >> t3;
		while (1) {
			cin >> t1;
			if (t1 == -1) break;
			cin >> t2;
			v[t3].push_back({ t1, t2 });
		}
	}
	int f_m = BFS(v, visit, 1);
	for (int i = 0; i <= n; i++) visit[i] = 0;
	BFS(v, visit, f_m);
	cout << mm;


	return 0;
}