#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> nodes(50);
int cnt = 0;
int del = 0;

void DFS(int n) {
	if (nodes[n].empty()) {
		cnt++;
		return;
	}

	for (int i = 0; i < nodes[n].size(); i++) DFS(nodes[n][i]);
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t, parent;
	cin >> n;
	vector<int> temp(n);

	for (int i = 0; i < n; i++) {
		cin >> temp[i];
		if (temp[i] == -1) parent = i;
	}
	cin >> del;
	for (int i = 0; i < n; i++) {
		if (i == del || temp[i] == -1) continue;
		else nodes[temp[i]].push_back(i);
	}
	
	if (del == parent) cout << 0;
	else {
		DFS(parent);
		cout << cnt;
	}
	return 0;
}