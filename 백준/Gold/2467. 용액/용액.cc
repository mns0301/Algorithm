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
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int s = 0, e = n - 1;
	int min = 2e9;
	int min_s = 0, min_e = n - 1;
	while (s != e) {
		int temp = v[e] + v[s];
		//cout << s << " " << e << " " << temp << "\n";
		if (min >= abs(temp)) {
			min_s = v[s];
			min_e = v[e];
			min = abs(temp);
		}
		if (temp > 0) e--;
		else if (temp < 0) s++;
		else break;
	}

	cout << min_s << " " << min_e;

	return 0;
}