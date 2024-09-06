#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int v[100][100];
vector<vector<long long>> dp(100, vector<long long>(100));

long long fun(int x, int y) {
	if (x >= n || y >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	if (v[y][x] == 0) return 0;
	if (dp[y][x] != 0) return dp[y][x];
	return dp[y][x] = fun(x + v[y][x], y) + fun(x, y + v[y][x]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}
	

	long long cnt = 0;
	cnt = fun(0, 0);
	cout << cnt;

	return 0;
}	