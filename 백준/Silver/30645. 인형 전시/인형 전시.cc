#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {

	int r, c, n;
	cin >> r >> c >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int index = 0;
	vector<int> line(c, 0);
	int cnt = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (index == n) break;
			if (v[index] > line[j]) {
				line[j] = v[index];
				cnt++;
				index++;
			}
			else {
				index++;
				j--;
			}
		}
	}

	cout << cnt;

	return 0;
}