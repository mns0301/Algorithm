#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long int m;
	cin >> n >> m;
	vector<long long int> v;
	long long int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	long long int s = 0, e = 1e9, mid = (s + e) / 2;
	long long int sum = 0;
	int sz = v.size();

	while (e != mid) {
		sum = 0;
		mid = (s + e) / 2;
		for (int i = 0; i < sz; i++) sum += (v[i] > mid ? v[i] - mid : 0);
		if (sum < m) e = mid - 1;
		else if (sum > m) s = mid + 1;
		else break;
		//cout << mid << "\n";
	}

	cout << mid;

	return 0;
}	