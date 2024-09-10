#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	vector<int> bag(m);
	for (int i = 0; i < m; i++) cin >> bag[i];
	sort(v.begin(), v.end());
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;
	long long sum = 0;
	int index = 0;
	for (int i = 0; i < m; i++) {
		while (index != n && v[index].first <= bag[i]) {
			pq.push(v[index].second);
			index++;
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}