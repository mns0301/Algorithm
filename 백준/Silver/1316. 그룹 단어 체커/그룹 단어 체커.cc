#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string arr;
	bool tf = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr;

		for (int x = 0; x < arr.size(); x++) {
			tf = 0;
			int y = x + 1;

			for (y; y < arr.size(); y++) {
				if (arr[x] == arr[y] && tf == 1) break;
				if (arr[x] != arr[y]) tf = 1;
			}
			//cout << y << "\n";
			if (tf == 1 && y != arr.size()) break;
			if (x == arr.size() - 1) cnt++;
		}
	}
	cout << cnt;

	return 0;
}