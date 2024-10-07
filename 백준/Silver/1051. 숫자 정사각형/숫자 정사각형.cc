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

int main() {
	fastio;

	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int volumn = 0;

	int x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;
	for (int y1 = 0; y1 < n; y1++) {
		for (int x1 = 0; x1 < m; x1++) {
			for (int x2 = x1; x2 < m; x2++) {
				for (int y2 = y1; y2 < n; y2++) {
					if (y2-y1 == x2 - x1 && v[y1][x1] == v[y2][x1] && v[y1][x2] == v[y2][x2] && v[y1][x1] == v[y2][x2]) volumn = max(volumn, (x2 - x1 + 1) * (y2 - y1 + 1));
				}
			}
		}
	}
	cout << volumn;

	return 0;
}
