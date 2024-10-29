#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t;
	cin >> n; 
	int b = -1e6, a = 1e6;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (a > t) a = t;
		if (b < t) b = t;
	}
	cout << a << " " << b;
}