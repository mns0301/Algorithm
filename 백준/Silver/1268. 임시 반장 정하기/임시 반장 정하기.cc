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
	vvi stu(n, vi(5));
	vi ans(n, 0);

	int mi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) cin >> stu[i][j];
		for (int j = i-1; j >= 0; j--) {
			for (int k = 0; k < 5; k++) {
				if (stu[i][k] == stu[j][k]) {
					ans[i]++;
					ans[j]++;
					break;
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		if (ans[mi] < ans[i]) mi= i; 
	}
	cout << mi + 1;

	return 0;
}