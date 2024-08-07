#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int>>& v, queue<pair<int, int>>& pos, int y, int x, int n, int m) {
	if (x < 0 || y < 0 || x == m || y == n) return 0;
	if (v[y][x] == 0) {
		v[y][x] = 1;
		pos.push(make_pair(y, x));
		return 1;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	int n, m;
	cin >> m >> n;
	int day = -1;
	int changed = 0;
	vector<vector<int>> v(n, vector<int>(m, 0));
	queue<pair<int, int>> pos;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) {
				pos.push(make_pair(i, j));
				changed++;
			}
		}
	}

	int x = 0, y = 0, temp = 0;
	while (changed != 0) {
		temp = 0;
		for (int i = 0; i < changed; i++) {
			y = pos.front().first;
			x = pos.front().second;
			pos.pop();
			temp += BFS(v, pos, y - 1, x, n, m);
			temp += BFS(v, pos, y, x - 1, n, m);
			temp += BFS(v, pos, y + 1, x, n, m);
			temp += BFS(v, pos, y, x + 1, n, m);
		}
		day++;
		changed = temp;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << v[i][j] << " ";
			if (v[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
		//cout << "\n";	
	}
	cout << day;

	return 0;
}