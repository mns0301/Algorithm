#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

void DFS(vector<int> v[], int visit[], int r, int* cnt) {
	if (visit[r] == 0) {
		visit[r] = (*cnt)++;
		for (int i = 0; i < v[r].size(); i++) DFS(v, visit, v[r][i], cnt);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, m, r;
	cin >> n >> m >> r;
	vector<int> v[100001];
	int* visit = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++) visit[i] = 0;
	int cnt = 1;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) sort(v[i].begin(), v[i].end());
	DFS(v, visit, r, &cnt);

	for (int i = 1; i < n + 1; i++) cout << visit[i] << "\n";

	free(visit);
	return 0;
}