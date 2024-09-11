#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

map<long long, long long> ma;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

vector<long long> sieve(long long n) {
	vector<bool> is_prime(n + 1, true);
	vector<long long> primes;
	is_prime[0] = is_prime[1] = false;
	for (long long i = 2; i <= n; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (long long j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return primes;
}

long long countDivisors(long long n) {
	long long count = 0;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			count++; // i가 n의 약수
			if (i != n / i) count++; // n / i가 n의 약수
		}
	}
	return count;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long sz_d, sz_m;
	cin >> sz_d >> sz_m;
	vector<long long> d(sz_d);
	vector<long long> m(sz_m);
	for (long long i = 0; i < sz_d; i++) cin >> d[i];
	for (long long j = 0; j < sz_m; j++) cin >> m[j];

	long long min = d[0];
	for (long long i = 1; i < sz_d; i++) {
		min = min / gcd(min, d[i]) * d[i];
	}
	long long max = m[0];
	for (long long i = 1; i < sz_m; i++) {
		max = gcd(max, m[i]);
	}

	if (max % min) {
		cout << 0;
		return 0;
	}
	
	long long m_value = max / min;
	long long result = countDivisors(m_value);
	cout << result;


	return 0;
}