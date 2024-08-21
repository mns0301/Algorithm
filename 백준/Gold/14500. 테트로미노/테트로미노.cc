#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void chk(int v[500][500], int* max, vector<pair<int, int>> pas, int cnt, int temp, pair<int, int> cur, int n, int m) {

	if (cur.first == n || cur.second == m || cur.first < 0 || cur.second < 0) return;
	if (cnt > 1) {
		if (cur == pas[cnt-2]) return;
	}
	else pas.push_back(cur);
	temp += v[cur.first][cur.second];

	if (cnt == 3) {
		if (temp > *max) *max = temp;
		return;
	}

	chk(v, max, pas, cnt + 1, temp, { cur.first + 1, cur.second }, n, m);
	chk(v, max, pas, cnt + 1, temp, { cur.first, cur.second + 1 }, n, m);
	chk(v, max, pas, cnt + 1, temp, { cur.first - 1, cur.second }, n, m);
	chk(v, max, pas, cnt + 1, temp, { cur.first, cur.second - 1 }, n, m);

	return;
}

void xx(int v[500][500], int* max, pair<int, int> cur, int n, int m) {
	vector<int> temp(4, 0);
	if (cur.first + 1 != n) temp[0] = v[cur.first + 1][cur.second];
	if (cur.second + 1 != m) temp[1] = v[cur.first][cur.second + 1];
	if (cur.first > 0) temp[2] = v[cur.first - 1][cur.second];
	if (cur.second > 0) temp[3] = v[cur.first][cur.second - 1];
	
	sort(temp.begin(), temp.end(), greater<int>());
	int x = v[cur.first][cur.second];
	x += (temp[0] + temp[1] + temp[2]);
	if (x > *max) *max = x;

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int v[500][500] = { 0 };
	vector<pair<int, int>> pas;
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> v[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			chk(v, &max, pas, 0, 0, {i, j}, n, m);
			xx(v, &max, { i, j }, n, m);
		}
	}

	
	cout << max;

	return 0;
}