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

	int n;
	cin >> n;
	vi v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	vi ans(n, 0);

	for (int i = 0; i < n; i++) {
		int cnt = v[i];
		int pos = 0;

		while (1) {
			if (ans[pos] == 0 && cnt == 0) {
				ans[pos] = i + 1;
				break;
			}
			else if (ans[pos] == 0) pos++, cnt--;
			else pos++;
		}
	}

	for (int i = 0; i < n; i++) cout << ans[i] << " ";


	return 0;
}