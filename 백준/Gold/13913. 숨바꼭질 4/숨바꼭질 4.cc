#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


void find(vector<int>& v, vector<int>& xx, int n, int k) {
	priority_queue<pair<int, pair<int, vector<int>>>> q;
	
	q.push({ 0, {n, xx} });
	v[n] = 0;

	while (!q.empty()) {
		n = q.top().second.first;
		int cost = -q.top().first;
		xx = q.top().second.second;
		q.pop();

		if (cost < v[n]) v[n] = cost;
		if (v[n] < cost) continue;
		if (n > 200000 || n < 0) continue;
		if (n == k) {
			xx.push_back(n);
			break;
		}
		xx.push_back(n);

		if (n != 200000 && v[n + 1] == 1e9) {
			q.push({ -cost - 1, {n + 1, xx} });
		}
		if (n != 0 && v[n - 1] == 1e9) {
			q.push({ -cost - 1, {n - 1, xx} });
		}
		if (n <= 100000 && v[2 * n] == 1e9) {
			q.push({ -cost - 1, {2 * n, xx} });
		}
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	if (n < k) {
		vector<int> v(200001, 1e9);
		vector<int> xx;
		find(v, xx, n, k);

		cout << v[k] << "\n";
		for (int i = 0; i < xx.size(); i++) cout << xx[i] << " ";
	}
	else {
		cout << n - k << "\n";
		for (int i = n; i >= k; i--) cout << i << " ";
	}

	return 0;
}