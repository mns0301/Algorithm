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

	int n, m;
	deque<int> d;
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) d.push_back(i + 1);
	
	while (m--) {
		int t, cnt = 0;
		cin >> t;

		while (t != d.front()) {
			cnt++;
			d.push_back(d.front());
			d.pop_front();
		}
		ans += min(cnt, n - cnt);
		n--;
		d.pop_front();
	}

	cout << ans;

	return 0;
}