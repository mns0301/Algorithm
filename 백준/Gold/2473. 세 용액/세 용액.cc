#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	long long min = 1e18;
	int min_s = 1, min_e = n - 1, min_i = 0;


	for (int i = 0; i < n - 1; i++) {
		int s = i + 1, e = n - 1;

		while (s != e) {
			long long temp = v[e] + v[s] + v[i];
			if (min >= llabs(temp)) {
				min_s = v[s];
				min_e = v[e];
				min_i = v[i];
				min = llabs(temp);
			}
			if (temp > 0) e--;
			else if (temp < 0) s++;
			else break;
		}
	}

	cout << min_i << " " << min_s << " " << min_e;

	return 0;
}