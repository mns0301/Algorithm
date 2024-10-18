#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <deque>
#include <queue>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define str string
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define f(i, n) for(int i = 0; i < n; i++)

int n, m;
vvi v;
vvi dp;
vvi ans;
vi group;

void input();
void fun();
void output();

void BFS(pii p) {
	queue<pii> q;
	q.push(p);
	int cnt = 0;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (v[y][x]) continue;
		if (dp[y][x]) continue;

		dp[y][x] = group.size();
		cnt++;

		if (y > 0 && dp[y - 1][x] == 0) q.push({ y - 1, x });
		if (x > 0 && dp[y][x - 1] == 0) q.push({ y, x - 1 });
		if (y < n - 1 && dp[y + 1][x] == 0) q.push({ y + 1, x });
		if (x < m - 1 && dp[y][x + 1] == 0) q.push({ y, x + 1 });

	}

	group.push_back(cnt);
}

void input() {
	cin >> n >> m;
	str temp;
	v.resize(n);
	dp.resize(n);
	ans.resize(n);
	f(i, n) {
		v[i].resize(m);
		dp[i].resize(m);
		ans[i].resize(m);
	}

	group.push_back(0);

	f(i, n) {
		cin >> temp;
		f(j, m) v[i][j] = temp[j] - '0';
	}

}

void fun() {
	f(i, n) {
		f(j, m) {
			if (v[i][j]) continue;
			if (dp[i][j]) continue;
			BFS({ i, j });
		}
	}
	f(i, n) {
		f(j, m) {
			if (!v[i][j]) continue;

			int temp = 1;
			vi t;
			if (i > 0) {
				temp += group[dp[i - 1][j]];
				t.push_back(dp[i-1][j]);
			}
			if (j > 0) {
				f(k, t.size()) {
					if (dp[i][j-1] == t[k]) goto chk1;
				}
				temp += group[dp[i][j - 1]];
				t.push_back(dp[i][j-1]);
			}
			chk1:
			if (i < n - 1) {
				f(k, t.size()) {
					if (dp[i+1][j] == t[k]) goto chk2;
				}
				temp += group[dp[i + 1][j]];
				t.push_back(dp[i+1][j]);
			}
			chk2:
			if (j < m - 1) {
				f(k, t.size()) {
					if (dp[i][j+1] == t[k]) goto chk3;
				}
				temp += group[dp[i][j + 1]];
			}
			chk3:
			ans[i][j] = temp % 10;
		}
	}
}

void output() {
	f(i, n) {
		f(j, m) cout << ans[i][j];
		cout << "\n";
	}
}

int main() {
	fastio;

	input();
	fun();
	output();

	return 0;
}