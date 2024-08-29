#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


void find(vector<int>& v, int n, int k) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, n });
	v[n] = 0;

	while (!q.empty()) {
		n = q.top().second;
		int cost = -q.top().first;
		q.pop();

		if (v[n] < cost) continue;
		if (cost < v[n]) v[n] = cost;
		if (n == k) break;
		if (n > 100000 || n < 0) continue;

		if (n != 100000 && v[n + 1] == 1e9) q.push({ -cost - 1, n + 1 });
		if (n != 0 && v[n - 1] == 1e9) q.push({ -cost - 1, n - 1 });
		if (n <= 50000 && v[2 * n] == 1e9) q.push({ -cost, 2 * n });

	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(100001, 1e9);
	find(v, n, k);;

	cout << v[k];

	return 0;
}