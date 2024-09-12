#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<string> v(20);
int word = 0;
vector<bool> visit(26, 0);

int dfs(int y, int x, int cnt) {
	//if (y < 0 || x < 0 || y == n || x == n) return cnt;
	visit[v[y][x] - 'A'] = 1;
	cnt++;
    //cout << v[y][x];
	if (y > 0 && !visit[v[y - 1][x] - 'A']) {
		word = max(word, dfs(y - 1, x, cnt));
	}
	if (x > 0 && !visit[v[y][x - 1] - 'A']) {
		word = max(word, dfs(y, x - 1, cnt));
	}
	if (y != n - 1 && !visit[v[y + 1][x] - 'A']) {
		word = max(word, dfs(y + 1, x, cnt));
	}
	if (x != m - 1 && !visit[v[y][x + 1] - 'A']) {
		word = max(word, dfs(y, x + 1, cnt));
	}
	visit[v[y][x] - 'A'] = 0;
	word = max(cnt, word);
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> v[i];
	dfs(0, 0, 0);

	cout << word;

	return 0;
}