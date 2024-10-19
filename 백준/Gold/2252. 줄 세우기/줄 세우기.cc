#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
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
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)

int n, m;
vi degree;
vvi v;
queue<int> q;
vi ans;

void input();
void fun();
void output();

void input() {
	cin >> n >> m;
	degree.resize(n+1);
	v.resize(n+1);

	f(i, m) {
		int t1, t2;
		cin >> t1 >> t2;
		degree[t2]++;
		v[t1].push_back(t2);
	}
	f(i, n + 1) {
		if (degree[i] == 0) q.push(i);
	}
	q.pop();
}

void fun() {
	while(q.size()) {
		int pos = q.front();
		q.pop();

		ans.push_back(pos);

		f(i, v[pos].size()) {
			degree[v[pos][i]]--;
			if (degree[v[pos][i]] == 0) q.push(v[pos][i]);
		}
	}
}

void output() {
	f(i, n) cout << ans[i] << " ";
}

int main() {
	fastio;

	input();
	fun();
	output();

	return 0;
}