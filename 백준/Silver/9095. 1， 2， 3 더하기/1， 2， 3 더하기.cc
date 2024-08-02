#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	vector<long long int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);

 	while (t--) {
		int n;
		cin >> n;
		for (int i = v.size(); i < n; i++) v.push_back(v[i - 1] + v[i - 2] + v[i - 3]);
		cout << v[n - 1] << "\n";
	}

	return 0;
}	