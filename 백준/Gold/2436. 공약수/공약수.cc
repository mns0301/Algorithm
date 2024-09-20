#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(long long int a, long long int b) {
	if (b % a) return gcd(b % a, a);
	else return a;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long int s, l;
	cin >> s >> l;
	long long int n1, n2, t1, t2;
	n1 = s;
	n2 = l;
	double xy = sqrt(l*s);
	for (int i = s; i <= xy; i += s) {
		t1 = i;
		t2 = l / t1 * s;
		if (gcd(t1, t2) == s && t1*t2/s == l) {
			if (t1 + t2 < n1 + n2) {
				n1 = t1;
				n2 = t2;
			}
		}
	}

	cout << n1 << " " << n2;

	return 0;
}