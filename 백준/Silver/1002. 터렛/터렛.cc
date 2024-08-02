#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		double x1, y1, r1;
		double x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dis2 = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
		double rs = (r2 + r1);
		double dis = sqrt(dis2);
		if (x1 == x2 && y1 == y2 && r1 == r2) cout << "-1\n";
		else if (x1 == x2 && y1 == y2 && r1 != r2) cout << "0\n";
		else if (dis + r1 < r2 || dis + r2 < r1) cout << "0\n";
		else if (dis + r1 == r2 || dis + r2 == r1) cout << "1\n";
		else if (dis > rs) cout << "0\n";
		else if (dis == rs) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}