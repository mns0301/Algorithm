#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(3 * n + 1, 1e9);
	v[n] = 0;
	for (int i = n; i > 0; i--) {
		if (v[1] != 1e9) break;
		if (i % 3 == 0) v[i / 3] = min(v[i / 3], v[i] + 1);
		if (i % 2 == 0) v[i / 2] = min(v[i / 2], v[i] + 1);
		v[i - 1] = min(v[i - 1], v[i] + 1);
	}

	int cnt = v[1];
	vector<int> ans;
	int x = 1;
	ans.push_back(x);
	cout << cnt << "\n";

	while (x != n) {
		if (v[3 * x] <= v[2 * x] && v[3 * x] <= v[x + 1]) x = 3 * x;
		else if (v[2 * x] <= v[x + 1]) x = 2 * x;
		else x = x + 1;

		ans.push_back(x);
	}
	
	while (ans.size()) {
		cout << ans.back() << " ";
		ans.pop_back();
	}
	
	return 0;
}