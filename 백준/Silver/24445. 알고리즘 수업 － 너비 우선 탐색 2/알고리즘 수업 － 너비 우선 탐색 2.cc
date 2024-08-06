#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <queue>
using namespace std;

void BFS(vector<int> v[], int visit[], int r, int* cnt) {
	queue<int> que;
	que.push(r);
	int temp;

	while (!que.empty()) {
		temp = que.front();
		que.pop();
		if (visit[temp] == 0) visit[temp] = (*cnt)++;
		else continue;

		int s = 0, e = v[temp].size();
		for (s; s < e; s++) que.push(v[temp][s]);
	}
	return;
}

bool compare(int a, int b) {
	return a > b;
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
	for (int i = 0; i < n + 1; i++) sort(v[i].begin(), v[i].end(), compare);
	BFS(v, visit, r, &cnt);

	for (int i = 1; i < n + 1; i++) cout << visit[i] << "\n";

	free(visit);
	return 0;
}