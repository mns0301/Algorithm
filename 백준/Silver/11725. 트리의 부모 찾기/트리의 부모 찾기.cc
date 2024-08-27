#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> BFS(vector<vector<int>> v) {
	queue<pair<int, int>> q;
	q.push({1, 0});
	vector<int> visit(v.size(), 0);
	visit[1] = 0;

	while (!q.empty()) {
		int parent = q.front().second;
		int child = q.front().first;
		q.pop();

		if (visit[child] != 0) continue;
		visit[child] = parent;

		for (int i = 0; i < v[child].size(); i++) {
			if (visit[v[child][i]] == 0) q.push({ v[child][i], child });
		}
	}

	return visit;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	int t1, t2;
	for (int i = 1; i < n; i++) {
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	vector<int> visit(BFS(v));

	for (int i = 2; i <= n; i++) {
		cout << visit[i] << "\n";
	}

	return 0;
}