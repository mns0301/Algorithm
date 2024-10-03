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

	int l, r;
	cin >> l >> r;

	int min_cnt = 100;
	for (int i = l; i <= r; i++) {
		int temp = i;
		int temp_cnt = 0;
		while (temp) {
			if (temp % 10 == 8) temp_cnt++;
			temp /= 10;
			if (temp_cnt >= min_cnt) break;
		}

		min_cnt = min(min_cnt, temp_cnt);
		if (min_cnt == 0) break;
	}

	cout << min_cnt;

	return 0;
}