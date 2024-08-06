#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void virus(vector<int> v[], int visit[], int r, int* cnt) {
	if (visit[r] != 0) return;
	visit[r] = 1;
	(*cnt)++;
	
	int s = 0, e = v[r].size();
	for (s; s < e; s++) virus(v, visit, v[r][s], cnt);

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v[101];
	int* visit = new int[n + 1] {0};
	int a, b;
	int cnt = -1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	virus(v, visit, 1, &cnt);
	cout << cnt;

	delete visit;
	return 0;
}