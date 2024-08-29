#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int find(vector<int>& v, int ans, int n, int k) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, n });
	v[n] = 0;
	int cnt = 0;
	while (!q.empty()) {
		n = q.top().second;
		int cost = -q.top().first;
		q.pop();

		if (cost > ans) break;
		if (cost < v[n]) v[n] = cost;
		if (v[n] < cost) continue;
		if (n > 100000 || n < 0) continue;
		if (n == k) {
			ans = cost;
			cnt++;
			continue;
		}

		if (n != 100000 && v[n + 1] == 1e9) q.push({ -cost - 1, n + 1 });
		if (n != 0 && v[n - 1] == 1e9) q.push({ -cost - 1, n - 1 });
		if (n <= 50000 && v[2 * n] == 1e9) q.push({ -cost - 1, 2 * n });

	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int ans = 1e9;

	vector<int> v(100001, 1e9);
	int cnt = find(v, ans, n, k);;

	cout << v[k] << "\n" << cnt;

	return 0;
}