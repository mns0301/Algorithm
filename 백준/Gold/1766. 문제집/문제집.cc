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

int n, m;
vi solve_level;
vi ans;
vvi solve_node;
vi degree;


void input() {
	cin >> n >> m;

	//solve_level.resize(n + 1);
	solve_node.resize(n + 1);
	//ans.resize(n + 1);
	degree.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		solve_node[t1].push_back(t2);
		degree[t2]++;
	}

	return;
}

void fun() {
	//priority_queue<pii> pq;
	priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		//if (degree[i] == 0) pq.push({ -i, i });
		if (degree[i] == 0) q.push(-i);
	}
	while (!q.empty()) {
		int time = -q.top();
		q.pop();

		ans.push_back(time);
	
		for (int i = 0; i < solve_node[time].size(); i++) {
			int temp = solve_node[time][i];
			degree[temp]--;
			if (degree[temp] == 0) {
				q.push(-temp);
			}
		}
	}

	return;
}

int main(void) {
	FIO;

	input();
	fun();

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	return 0;
}