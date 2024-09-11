#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

long long countDivisors(long long n) {
	long long count = 0;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			count++;
			if (i != n / i) count++;
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