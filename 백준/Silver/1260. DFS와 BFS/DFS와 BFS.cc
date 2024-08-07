#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<int> v[], int visit[], int n, int cnt, vector<int>& v1) {
	queue<int> que;
	que.push(n);
	int temp = 0;
	while (!que.empty()) {
		temp = que.front();
		que.pop();
		if (visit[temp] == 0) {
			visit[temp] = cnt++;
			v1.push_back(temp);
		}
		else continue;

		for (int i = 0; i < v[temp].size(); i++) que.push(v[temp][i]);
	}
	return;
}

void DFS(vector<int> v[], int visit[], int n, int& cnt, vector<int>& v2) {
	if (visit[n] == 0) {
		visit[n] = cnt++;
		v2.push_back(n);
		for (int i = 0; i < v[n].size(); i++) DFS(v, visit, v[n][i], cnt, v2);
	}
	return;
}

int main(void) {
	int n, m, s;
	cin >> n >> m >> s;
	int a, b;
	vector<int> v[1001];
	int* BFS_visit = new int[n + 1]();
	int* DFS_visit = new int[n + 1]();

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++) sort(v[i].begin(), v[i].end());
	int cnt = 1;
	vector<int> D;
	vector<int> B;
	DFS(v, DFS_visit, s, cnt, D);
	BFS(v, BFS_visit, s, 1, B);

	for (int i = 0; i < D.size(); i++) cout << D[i] << " ";
	cout << "\n";
	for (int i = 0; i < B.size(); i++) cout << B[i] << " ";

	delete[] BFS_visit;
	delete[] DFS_visit;
	return 0;
}	