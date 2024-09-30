#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FIO cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main(void) {
	FIO;

	int n, m;
	cin >> n >> m;
    cout << n/2+m/2 << "\n";

	for (int i = 2; i <= n; i += 2) {
		cout << i << " " << 1 << " " << i << " " << m << "\n";
	}
	for (int i = 2; i <= m; i += 2) {
		cout << 1 << " " << i << " " << n << " " << i << "\n";
	}

	return 0;
}