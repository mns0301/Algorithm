#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

int n, s, cnt;
vi v(20);

void fun(int i, int sum) {
	//if (i == n) return;
	//cout << sum << "\n";
	if (i != 0 && sum == s) cnt++;

	for (int x = i; x < n; x++) {
		fun(x + 1, sum + v[x]);
	}
}

int main() {
	fastio;

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> v[i];

	fun(0, 0);

	cout << cnt;

	return 0;
}		