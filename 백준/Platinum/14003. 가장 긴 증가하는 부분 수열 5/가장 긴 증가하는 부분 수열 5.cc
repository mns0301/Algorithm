#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	vector<int> lis;
	vector<int> l(n, 0);
	for (int i = 0; i < n; i++) {
		auto pos = lower_bound(lis.begin(), lis.end(), v[i]);
		l[i] = pos - lis.begin();
		if (pos == lis.end()) lis.push_back(v[i]);
		else *pos = v[i];
	}
	cout << lis.size() << "\n";
	int num = lis.size() - 1;
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {
		if (l[i] == num) {
			ans.push_back(v[i]);
			num--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";

	return 0;
}