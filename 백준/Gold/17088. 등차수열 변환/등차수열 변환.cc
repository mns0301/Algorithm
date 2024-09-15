#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr(vector<int> v, int a, int d) {
	int cnt = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == a + d * i) { continue; }
		else if (v[i] + 1 == a + d * i) {
			cnt++;
			continue;
		}
		else if (v[i] - 1 == a + d * i) {
			cnt++;
			continue;
		}
		else {
			cnt = -1;
			break;
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	int cnt = 1e9, cnt1;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	cnt1 = arr(v, v[0], v[1] - v[0]);
	if (cnt1 != -1) cnt = min(cnt1, cnt);
	cnt1 = arr(v, v[0], v[1] - v[0] + 1);
	if (cnt1 != -1) cnt = min(cnt1, cnt);
	cnt1 = arr(v, v[0], v[1] - v[0] - 1);
	if (cnt1 != -1) cnt = min(cnt1, cnt);

	cnt1 = arr(v, v[0] + 1, v[1] - v[0] - 2);
	if (cnt1 != -1) cnt = min(cnt1 + 1, cnt);
	cnt1 = arr(v, v[0] + 1, v[1] - v[0] - 1);
	if (cnt1 != -1) cnt = min(cnt1 + 1, cnt);
	cnt1 = arr(v, v[0] + 1, v[1] - v[0]);
	if (cnt1 != -1) cnt = min(cnt1 + 1, cnt);

	cnt1 = arr(v, v[0] - 1, v[1] - v[0] + 2);
	if (cnt1 != -1) cnt = min(cnt1 + 1, cnt);
	cnt1 = arr(v, v[0] - 1, v[1] - v[0] + 1);
	if (cnt1 != -1) cnt = min(cnt1 + 1, cnt);
	cnt1 = arr(v, v[0] - 1, v[1] - v[0]);
	if (cnt1 != -1) cnt = min(cnt1 + 1, cnt);

	if (cnt == 1e9) cout << -1;
	else cout << cnt;

	return 0;
}