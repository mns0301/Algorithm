#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	while (q--) {
		int a, d, x;
		cin >> a >> d >> x;
		int i = 0;
		while (1) {
			if (x <= a * i + i * (i - 1) / 2 * d) break;
			i++;
		}
		i--;
		cout << i + 1 << " " << x - (a * i + i * (i - 1) / 2 * d) << "\n";
	}
	
	return 0;
}