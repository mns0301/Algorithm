#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
int n;
int xx[15] = { -1, };
int yy[15] = { -1, };
int c1[30] = { -1, };
int c2[30] = { -1, };

void fun(int x) {
	if (x == n) {
		ans++;
		return;
	}
	if (xx[x] != -1) return;
	xx[x] = 1;
	for (int i = 0; i < n; i++) {
		if (yy[i] != -1) continue;
		if (c1[x + i] != -1) continue;
		if (c2[n - x + i] != -1) continue;
		yy[i] = 1;
		c1[x + i] = 1;
		c2[n - x + i] = 1;
		fun(x + 1);
		c2[n - x + i] = -1;
		c1[x + i] = -1;
		yy[i] = -1;
	}
	xx[x] = -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		xx[i] = -1;
		yy[i] = -1;
	}
	for (int i = 0; i < 2 * n; i++) {
		c1[i] = -1;
		c2[i] = -1;
	}

	fun(0);

	cout << ans;

	return 0;
}