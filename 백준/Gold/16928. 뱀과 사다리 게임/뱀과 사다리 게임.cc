#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> v[], vector<int>& visit) {
	queue<pair<int, int>> q;
	visit[1] = 0;
	q.push({1, visit[1]});
	int x = 0;
	int cnt = 0;

	while (!q.empty()) {
		x = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (x > 100) continue;
		if (visit[x] != 0 && visit[x] < cnt) continue;
		visit[x] = cnt;
		if (!v[x].empty()) q.push({ v[x][0], cnt});
		else {
			q.push({ x + 6, cnt + 1 });
			q.push({ x + 5, cnt + 1 });
			q.push({ x + 4, cnt + 1 });
			q.push({ x + 3, cnt + 1 });
			q.push({ x + 2, cnt + 1 });
			q.push({ x + 1, cnt + 1 });
		}
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v[101];
	vector<int> visit(101, 0);
	int s, e;

	for (int i = 0; i < n + m; i++) {
		cin >> s >> e;
		v[s].push_back(e);
	}

	BFS(v, visit);

	cout << visit[100];
    
	return 0;
}