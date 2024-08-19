#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<int>& visit, vector<int> node[], int y) {
	int size = node[y].size();

	for (int i = 0; i < size; i++) {
		if (visit[node[y][i]] == 1) continue;
		visit[node[y][i]] = 1;
		DFS(visit, node, node[y][i]);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<int> node[100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) node[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++) {
		vector<int> visit(100, 0);
		DFS(visit, node, i);
		v[i] = visit;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}