#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void fun(vector<int> v, vector<int> is, int m, int cnt) {
	if (m == cnt) {
		for (int i = 0; i < m - 1; i++) {
			if (is[i] > is[i + 1]) return;
		}

		for (int i = 0; i < m; i++) cout << is[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		is[cnt] = v[i];
		fun(v, is, m, cnt + 1);
		is[cnt] = v[i];
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
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] == v[i + 1]) v.erase(v.begin() + i--);
	}
	vector<int> bit(n, 0);
	vector<int> is(m, 0);
	fun(v, is, m, 0);

	return 0;
}