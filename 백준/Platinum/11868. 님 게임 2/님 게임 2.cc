#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		ans ^= t;
	}
	if (ans) cout << "koosaga";
	else cout << "cubelover";
	return 0;
}