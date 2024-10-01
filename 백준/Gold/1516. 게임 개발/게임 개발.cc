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

int n;
vi built_time, ans;
vvi build_node;
vi degree;

void input() {
	cin >> n;

	built_time.resize(n + 1);
	build_node.resize(n + 1);
	ans.resize(n + 1);
	degree.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> built_time[i];
		while (1) {
			int t;
			cin >> t;
			if (t == -1) break;

			build_node[t].push_back(i);
			degree[i]++;
		}
	}

	return;
}

void fun() {
	priority_queue<pii> pq;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) pq.push({ -built_time[i], i });
	}

	while (!pq.empty()) {
		int time = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		ans[pos] = time;

		for (int i = 0; i < build_node[pos].size(); i++) {
			int temp = build_node[pos][i];
			degree[temp]--;
			if (degree[temp] == 0) {
				pq.push({ -(time + built_time[temp]), temp });
			}
		}
	}

}

void print() {
	for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}

int main(void) {
	FIO;

	input();
	fun();
	print();

	return 0;
}