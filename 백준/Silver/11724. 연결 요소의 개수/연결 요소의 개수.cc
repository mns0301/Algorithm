#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void node(vector<int> v[], int visit[], int r) {
	if (visit[r] != 0) return;
	visit[r] = 1;
	
	int s = 0, e = v[r].size();
	for (s; s < e; s++) node(v, visit, v[r][s]);

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v[1001];
	int* visit = new int[n + 1] {0};
	int a, b;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++) {
		if (visit[i] != 0) continue;
		node(v, visit, i);
		cnt++;
	}

	cout << cnt;

	delete visit;
	return 0;
}	