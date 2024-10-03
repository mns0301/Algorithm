#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>

int main(void) {
	fastio;

	int n;
	cin >> n;
	vvi v(n + 1, vi(n + 1, 1e9));
	vi ans(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'Y') v[i][j + 1] = 1;
		}
		v[i][i] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] < 3) ans[i]++;
		}
	}
	int m = 0;
	for (int i = 1; i <= n; i++) m = max(m, ans[i] - 1);

	cout << m;

	return 0;
}