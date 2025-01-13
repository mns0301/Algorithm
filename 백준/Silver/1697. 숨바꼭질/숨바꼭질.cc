#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int find(vector<int>& v, int n, int k) {
	queue<int> que;
	queue<int> num;
	int temp = 0;
	int x = 0;
	que.push(n);
	num.push(0);

	while (!que.empty()) {
		temp = que.front();
		x = num.front();
		que.pop();
		num.pop();
		if (temp == k) break;
		if (temp > 200000 || temp < 0 || v[temp] != 0) continue;
		v[temp]++;
		que.push(temp - 1);
		que.push(temp + 1);
		que.push(2 * temp);
		num.push(x + 1);
		num.push(x + 1);
		num.push(x + 1);
	}
	return x;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(200001, 0);
	
	cout << find(v, n, k);;

	
	return 0;
}	