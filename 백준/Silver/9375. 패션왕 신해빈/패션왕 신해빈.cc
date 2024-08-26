#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<string, int> m;
		vector<int> v;
		string t1, t2;

		if (n == 0) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			cin >> t1 >> t2;
			m[t2]++;
		}
		for (auto i = m.begin(); i != m.end(); i++) v.push_back(i->second);
		
		int sum = v[0];
		for (int i = 1; i < v.size(); i++) sum = sum * (v[i] + 1) + v[i];
		cout << sum << "\n";
	}

	return 0;
}