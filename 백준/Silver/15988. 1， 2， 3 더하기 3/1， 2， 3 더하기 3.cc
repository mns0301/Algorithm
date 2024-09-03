#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	vector<long long> v(3);
	v[0] = 1;
	v[1] = 1;
	v[2] = 2;

	while (t--) {
		int n;
		cin >> n;
		for (int i = v.size(); i <= n; i++) v.push_back((v[i - 1] + v[i - 2] + v[i - 3]) % 1000000009);
		cout << v[n] << "\n";
	}

	return 0;
}