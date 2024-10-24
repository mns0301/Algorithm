#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <map>
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
vvi v;

void input();
void fun();
void output();

void input() {
	cin >> n >> m;
	v.resize(n + 1);
	f(i, n + 1) v[i].resize(n + 1);
	f(i, m) {
		int t1, t2;
		cin >> t1 >> t2;
		v[t1][t2] = 2;
		v[t2][t1] = 1;
	}
}

void fun() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i][k] == 2 && v[k][j] == 2) v[i][j] = 2, v[j][i] = 1;
			}
		}
	}
}

void output() {

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (v[i][j]) cnt++;
		}
		cout << n - cnt - 1 << "\n";
	}
}

int main() {
	fastio;

	input();
	fun();
	output();

	return 0;
}