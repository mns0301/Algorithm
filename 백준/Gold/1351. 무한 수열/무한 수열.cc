#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long int an(map<long long int, long long int>& v, long long int n, long long int p, long long int q) {
	if (v[n] != NULL) return v[n];
	else v[n] = an(v, n / p, p, q) + an(v, n / q, p, q);
	return v[n];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int n, p, q;
	cin >> n >> p >> q;
	map<long long int, long long int> v;
	v[0] = 1;

	v[n] = an(v, n, p, q);

	cout << v[n];

	return 0;
}