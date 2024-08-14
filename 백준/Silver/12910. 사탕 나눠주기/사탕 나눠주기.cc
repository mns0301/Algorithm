#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp > n) continue;
		v[temp]++;
	}
	int sum = 0;
	int mul = 1;
	for (int i = 1; i < n + 1; i++) {
		if (v[i] == 0) break;
		mul *= v[i];
		sum += mul;
	}
	cout << sum;
}