#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vvi vector<vi>
#define FIO cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int n, k, w;

void input(vi& built_time, vi& ans, vi& degree, vvi& build_node) {
	cin >> n >> k;

	built_time.resize(n + 1);
	build_node.resize(n + 1);
	ans.resize(n + 1);
	degree.resize(n + 1);

	for (int i = 1; i <= n; i++) cin >> built_time[i];
	for (int i = 0; i < k; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		build_node[t1].push_back(t2);
        degree[t2]++;
	}
	cin >> w;

	return;
}

void fun(vi& built_time, vi& ans, vi& degree, vvi& build_node) {
	priority_queue<pii> pq;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) pq.push({ -built_time[i], i });
	}

	while (!pq.empty()) {
		int time = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		ans[pos] = time;
		if (pos == w) break;

		for (int i = 0; i < build_node[pos].size(); i++) {
			int temp = build_node[pos][i];
			degree[temp]--;
			if (degree[temp] == 0) {
				pq.push({ -(time + built_time[temp]), temp });
			}
		}
	}

	return;
}

int main(void) {
	FIO;

	int T;
	cin >> T;
	while (T--) {
		vi built_time(1001, 0), ans(1001, 0);
		vvi build_node;
		vi degree(1001, 0);
		input(built_time, ans, degree, build_node);
		fun(built_time, ans, degree, build_node);
		cout << ans[w] << "\n";
	}

	return 0;
}