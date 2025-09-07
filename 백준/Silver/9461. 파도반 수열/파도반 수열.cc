#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long int* dt = new long long int[100] {1, 1, 1};
	
	
	int t;
	cin >> t;
	int len = 3;

	for (int x = 0; x < t; x++) {
		int n;
		cin >> n;
		for (int i = len; i < n; i++) dt[i] = dt[i - 2] + dt[i - 3];
		if (n > len) len = n;

		cout << dt[n - 1] << "\n";
	}

	delete dt;

	return 0;
}	