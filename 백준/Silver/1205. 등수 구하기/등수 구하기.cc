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

	int n, new_n, p;
	cin >> n >> new_n >> p;
	vi v(51, 0);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v[i] = -t;
	}
	int rank_l = lower_bound(v.begin(), v.begin() + n, -new_n) - v.begin() + 1;
	int rank_u = upper_bound(v.begin(), v.begin() + n, -new_n) - v.begin() + 1;
	
	if (rank_l == rank_u) {
		if (rank_l <= p) cout << rank_l;
		else cout << -1;
	}
	else {
		if (rank_l <= p && rank_u > p) cout << -1;
		else cout << rank_l;
	}

	return 0;
}