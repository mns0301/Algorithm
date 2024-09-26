#include <iostream>
using namespace std;

long long fun_r(long long r, long long n, long long mod) {
	if (n == 1) return r % mod;
	long long t = fun_r(r, n / 2, mod) % mod;
	if (n % 2 == 0) return ((t % mod) * (t % mod)) % mod;
	else return (((t % mod) * (t % mod)) % mod * (r % mod)) % mod;
}

long long fun_sn(long long r, long long n, long long mod) {
	if (n == 1) return 1;
	if (n % 2 == 0) return ((fun_sn(r, n / 2, mod) % mod) % mod * ((fun_r(r, n / 2, mod) + 1) % mod)) % mod;
	else return (fun_sn(r, n-1, mod) % mod + fun_r(r, n - 1, mod) % mod) % mod;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long a, r, n, mod;
	cin >> a >> r >> n >> mod;
	cout << ((a % mod) * fun_sn(r, n, mod)) % mod;

	return 0;
}