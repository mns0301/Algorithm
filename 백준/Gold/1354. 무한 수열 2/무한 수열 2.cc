#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long int an(map<long long int, long long int>& v, long long int n, long long int p, long long int q, long long int x, long long int y) {
	if (n <= 0) return 1;
	if (v[n] != NULL) return v[n];
	else v[n] = an(v, n / p - x, p, q, x, y) + an(v, n / q - y, p, q, x, y);
	return v[n];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int n, p, q, x, y;
	cin >> n >> p >> q >> x >> y;
	map<long long int, long long int> v;

	v[n] = an(v, n, p, q, x, y);

	cout << v[n];

	return 0;
}