#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main() {
	fastio;

	long long n;
	cin >> n;
	vector<long long> v(n + 1, 0);
	for (long long i = 1; i <= n; i++)
		cin >> v[i];

	long long ans = 2 * n + v[n];
	for (long long i = 1; i <= n; i++) 
		ans += 2 * v[i] + abs(v[i] - v[i - 1]);

	cout << ans;
	return 0;
}