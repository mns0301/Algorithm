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
	lis.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		auto pos = lower_bound(lis.begin(), lis.end(), v[i]);
		if (pos == lis.end()) lis.push_back(v[i]);
		else *pos = v[i];
	}
	cout << lis.size();

	return 0;
}