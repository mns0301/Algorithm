#include <iostream>
#include <vector>
#include <algorithm>
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

	ll n, l;
	cin >> n >> l;

	for (ll i = l; i <= 100; i++) {
		ll temp = (i - 1) * (i) / 2;
		if (n < temp) break;
		if ((n - temp) % i == 0) {
			ll a = (n - temp) / i;
			for (ll j = 0; j < i; j++) {
				cout << a + j << " ";
			}
			return 0;
		}
	}
	cout << -1;

	return 0;
}