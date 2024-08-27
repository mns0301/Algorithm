#include <iostream>
using namespace std;

long long fun(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	if (b == 0) return 1;

	long long temp = fun(a, b / 2, c);
	if (b % 2 == 0) return temp * temp % c;
	else return temp * temp % c * a % c;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long a, b, c;
	cin >> a >> b >> c;
	long long ans = fun(a, b, c);
	
	cout << ans;

	return 0;
}