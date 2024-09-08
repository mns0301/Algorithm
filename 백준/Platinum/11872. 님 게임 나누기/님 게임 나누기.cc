#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int t;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t % 4 == 3) ans ^= t + 1;
		else if (t % 4 == 0) ans ^= t - 1;
		else ans ^= t;
	}
	if (ans) cout << "koosaga";
	else cout << "cubelover";
	return 0;
}