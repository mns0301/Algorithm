#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int len;
	string str;
	cin >> len >> str;
	int r = 0, u = 0, x = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'R') r++;
		else if (str[i] == 'U') u++;
		else x++;
	}

	cin >> len;
	int px, py;
	int cnt = 0;
	int temp;
	for (int i = 0; i < len; i++) {
		cin >> px >> py;
		temp = min(px, py) - 1;
		if (temp >= x) {
			px -= x;
			py -= x;
		}
		else if (temp < x) {
			px -= temp;
			py -= temp;
		}

		if ((px >= 1 && py >= 1) && (px - r <= 1 && py - u <= 1)) cnt++;
	}

	cout << cnt;

	return 0;
}