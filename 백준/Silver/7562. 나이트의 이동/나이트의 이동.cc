#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int n, pair<int, int> s, pair<int, int> e) {
	queue<pair<int, int>> q;
	queue<int> c;
	q.push(s);
	c.push(0);
	vector<vector<int>> v(n, vector(n, 0));

	while (q.size()) {
		s = q.front();
		int cost = c.front();
		q.pop();
		c.pop();

		if (s.first < 0 || s.second < 0 || s.first >= n || s.second >= n) continue;
		if (v[s.second][s.first] != 0) continue;
		else v[s.second][s.first] = cost;
		if (s == e) break;

		cost++;
		q.push({ s.first + 2, s.second + 1 });
		c.push(cost);
		q.push({ s.first + 2, s.second - 1 });
		c.push(cost);
		q.push({ s.first - 2, s.second + 1 });
		c.push(cost);
		q.push({ s.first - 2, s.second - 1 });
		c.push(cost);
		q.push({ s.first + 1, s.second + 2 });
		c.push(cost);
		q.push({ s.first + 1, s.second - 2 });
		c.push(cost);
		q.push({ s.first - 1, s.second + 2 });
		c.push(cost);
		q.push({ s.first - 1, s.second - 2 });
		c.push(cost);
	}

	cout << v[e.second][e.first] << "\n";
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int l;
		cin >> l;
		pair<int, int> s, e;
		int t1, t2;
		cin >> t1 >> t2;
		s = make_pair(t1, t2);
		cin >> t1 >> t2;
		e = make_pair(t1, t2);

		bfs(l, s, e);
	}

	return 0;
}