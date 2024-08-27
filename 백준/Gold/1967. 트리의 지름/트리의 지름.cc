#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DFS(vector<vector<int>>& di, vector<int>& ans, int x, int& result) {
	int f_m = 0, s_m = 0;

	for (int i = 0; i < di[x].size(); i++) {
		int temp = DFS(di, ans, di[x][i], result);
		if (temp > f_m) {
			s_m = f_m;
			f_m = temp;
		}
		else if (temp > s_m) s_m = temp;
	}
	result = max(result, f_m + s_m);

	return ans[x] + f_m;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<vector<int>> di(n + 1);
	vector<int> ans(n + 1, 0);
	int t1, t2, t3;
	
	for (int i = 1; i < n; i++) {
		cin >> t1 >> t2 >> t3;
		ans[t2] = t3;
		di[t1].push_back(t2);
	}

	int max = 0;
	DFS(di, ans, 1, max);
	

	cout << max;
	return 0;
}