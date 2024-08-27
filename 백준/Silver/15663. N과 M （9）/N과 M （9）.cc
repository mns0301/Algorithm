#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void fun(vector<int> v, vector<int> bit, vector<int> is, int m, int cnt) {
	if (m == cnt) {
		for (int i = 0; i < m; i++) cout << is[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (bit[i] == 1) continue;
		if (is[cnt] == v[i]) continue;
		bit[i] = 1;
		is[cnt] = v[i];
		fun(v, bit, is, m, cnt + 1);
		bit[i] = 0;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	vector<int> bit(n, 0);
	vector<int> is(m, 0);
	fun(v, bit, is, m, 0);

	return 0;
}