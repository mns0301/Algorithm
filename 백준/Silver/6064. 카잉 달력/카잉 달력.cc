#include <iostream>
using namespace std;

int mulnum(int a, int b) {
	if (a % b == 0) return b;
	else return mulnum(b, a % b);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		bool check = false;
		int max = m * n;
		max /= (m > n ? mulnum(m, n) : mulnum(n, m));
		int i, j;
		for (i = x; i <= max; i += m) {
			if (i == y) {
				check = true;
				break;
			}
			else if (i > y) {
				y += n;
				i -= m;
			}
		}

		if (check) cout << i << "\n";
		else cout << "-1\n";
	}
	
	return 0;
}