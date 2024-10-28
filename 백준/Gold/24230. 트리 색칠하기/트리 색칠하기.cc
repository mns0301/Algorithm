#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)

int main() {
	fastio;

	int n, cnt = 0, t1, t2;
	cin >> n;
	vvi v(n+1);
	vi color(n+1), visit(n+1, 0);
	for (int i = 1; i <= n; i++) cin >> color[i];
	f(i, n-1) {
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}

	queue<pii> q;
	q.push({0, 1});
	visit[1] = 1;

	while (q.size()) {
		int col = q.front().first;
		int num = q.front().second;
		q.pop();

		if (col != color[num]) cnt++;

		f(i, v[num].size()) {
			if (visit[v[num][i]] == 0) {
				visit[v[num][i]] = 1;
				q.push({color[num], v[num][i]});
			}
		}
	}

	cout << cnt;

	return 0;
}