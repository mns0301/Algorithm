#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main() {
	fastio;

	int n;
	cin >> n;

	vector<int> wi(n), visited(n);
	vector<vector<int>> w(n, vector<int>(n)), graph(n);
	int ans = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; i++) {
		cin >> wi[i];
		pq.push({wi[i], i});
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i==j) continue;
			graph[i].push_back(j);
		}
	}

	while (pq.size())
	{
		int weight = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (visited[now])
			continue;

		visited[now] = 1;
		ans += weight;
		for (int nxt : graph[now])
		{
			if (visited[nxt] == 1)
				continue;

			pq.push({w[now][nxt], nxt});
		}
	}

	cout << ans;

	return 0;
}