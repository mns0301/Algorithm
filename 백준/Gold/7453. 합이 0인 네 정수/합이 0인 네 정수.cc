#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
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

int main() {
	fastio;

	ll n, cnt = 0;
	cin >> n;
	vector<array<ll, 4>> v(n);
	for (ll i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
	ll sz = n * n;
	vector<ll> v1(sz), v2(sz);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			v1[n * i + j] = v[i][0] + v[j][1];
			v2[n * i + j] = v[i][2] + v[j][3];
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	for (ll i = 0; i < sz; i++) {
		ll index1 = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		ll index2 = upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		if (index1 != sz && v1[i] + v2[index1] == 0) {
			cnt += index2 - index1;
		}
	}

	cout << cnt;

	return 0;
}
