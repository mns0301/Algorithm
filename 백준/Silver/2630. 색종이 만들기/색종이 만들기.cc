#include <iostream>
#include <algorithm>
using namespace std;

int cnt(int a[128][128], int n1, int n2, int n, int* w, int* b) {
	if (n2 == n) {
		if ((a[0][0] != a[n1][0]) || (a[n1][0] != a[0][n1]) || (a[0][n1] != a[n1][n1])) {
			if (a[0][0] == 1) *b += 1;
			else if (a[0][0] == 0) *w += 1;
			if (a[0][n1] == 1) *b += 1;
			else if (a[0][n1] == 0) *w += 1;
			if (a[n1][0] == 1) *b += 1;
			else if (a[n1][0] == 0) *w += 1;
			if (a[n1][n1] == 1) *b += 1;
			else if (a[n1][n1] == 0) *w += 1;
		}
		else {
			if (a[0][0] == 1) *b += 1;
			else if (a[0][0] == 0) *w += 1;
		}
		return 0;
	}
	
	for (int i = 0; i < n; i += n2) {
		for (int j = 0; j < n; j += n2) {
			if ((a[i][j] != a[i][j + n1]) || (a[i][j + n1] != a[i + n1][j]) || (a[i + n1][j] != a[i + n1][j + n1])) {
				if (a[i][j] == 1) *b += 1;
				else if (a[i][j] == 0) *w += 1;
				if (a[i][j + n1] == 1) *b += 1;
				else if (a[i][j + n1] == 0) *w += 1;
				if (a[i + n1][j] == 1) *b += 1;
				else if (a[i + n1][j] == 0) *w += 1;
				if (a[i + n1][j + n1] == 1) *b += 1;
				else if (a[i + n1][j + n1] == 0) *w += 1;
				a[i][j] = 2;
			}
		}
	}

	return cnt(a, 2 * n1, 2 * n2, n, w, b);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[128][128];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}

	int w = 0;
	int b = 0;

	cnt(a, 1, 2, n, &w, &b);

	cout << w << "\n" << b;

	return 0;
}