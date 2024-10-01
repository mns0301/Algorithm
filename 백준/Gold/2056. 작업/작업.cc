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
vi solve_time;
//vi ans;
vvi solve_node;
vi degree;
int ans = 0;

void input() {
	cin >> n;

	solve_time.resize(n + 1);
	solve_node.resize(n + 1);
	//ans.resize(n + 1);
	degree.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> solve_time[i] >> m;
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			solve_node[t].push_back(i);
			degree[i]++;
		}
	}

	return;
}

void fun() {
	priority_queue<pii> pq;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) pq.push({ -solve_time[i], i});
	}
	while (!pq.empty()) {
		int time = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		
		ans = time;
	
		for (int i = 0; i < solve_node[pos].size(); i++) {
			int temp = solve_node[pos][i];
			degree[temp]--;
			if (degree[temp] == 0) {
				pq.push({ -(time + solve_time[temp]), temp });
			}
		}
	}

	return;
}

int main(void) {
	FIO;

	input();
	fun();

	cout << ans;
		
	return 0;
}