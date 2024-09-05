#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n + 2, 0);
	v[1] = 1;
	for (int i = 2; i <= n; i+=2) {
		v[i] = (v[i - 1] + v[i / 2]) % 1000000000;
		v[i + 1] = v[i] % 1000000000;
	}

	cout << v[n];

	return 0;
}