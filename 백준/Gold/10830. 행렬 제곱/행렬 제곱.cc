#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mul_met(vector<vector<int>> m1, vector<vector<int>> m2) {
	int n = m1.size();
	vector<vector<int>> ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ans[i][j] += m1[i][k] * m2[k][j];
			}
			ans[i][j] %= 1000;
		}
	}
	return ans;
}

vector<vector<int>> mm(vector<vector<int>>& m, long long b) {
	if (b == 1) return m;
	vector<vector<int>> temp(mm(m, b / 2));
	if (b % 2) return mul_met(mul_met(temp, temp), m);
	else return mul_met(temp, temp);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long int b;
	cin >> n >> b;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}

	v = mm(v, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << v[i][j] % 1000 << " ";
		cout << "\n";
	}


	return 0;
}