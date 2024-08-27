#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int BFS(int n1, int n2) {
	queue<pair<int, int>> q;
	q.push({n2, 1});

	while (!q.empty()) {
		n2 = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (n1 == n2) return cnt;

		if (n2 % 10 == 1 && n2 / 10 != 0) q.push({ n2 / 10, cnt + 1 });
		if (n2 % 2 == 0) q.push({ n2 / 2, cnt + 1 });
	}

	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n1, n2;
	cin >> n1 >> n2;

	cout << BFS(n1, n2);

	return 0;
}