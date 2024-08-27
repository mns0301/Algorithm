#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void fun(vector<int> v, vector<int> is, int m, int cnt) {
	if (m == cnt) {
		for (int i = 0; i < m; i++) cout << v[is[i]] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (find(is.begin(), is.end(), i) != is.end()) continue;
		is.push_back(i);
		fun(v, is, m, cnt + 1);
		is.pop_back();
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

	fun(v, {}, m, 0);

	return 0;
}