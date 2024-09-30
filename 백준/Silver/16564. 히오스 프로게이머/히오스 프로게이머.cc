#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long m;
	cin >> n;
	cin >> m;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	long long l = 1, r = 1e10;	
	long long temp = 0;
	long long mid = (l + r) / 2;


	while (l + 1 < r) {
		mid = (l + r) / 2;
		temp = 0;

		for (int i = 0; i < n; i++) {
			if (mid > v[i]) temp += mid - v[i];
		}
		
		if (temp > m) r = mid;
		else l = mid;
	}

	cout << l;
	return 0;
}