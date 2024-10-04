#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>

int n, m;
vi v;
vi arr;

void input() {
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
}

void print() {
	for (int i = 0; i < m; i++) cout << arr[i] << " ";
	cout << "\n";
}

void fun(int cnt, int x) {
	if (x == m) {
		print();
		return;
	}

	for (int i = cnt; i < n; i++) {
		arr.push_back(v[i]);
		fun(i + 1, x + 1);
		arr.pop_back();
	}
	return;
}

int main(void) {
	fastio;

	input();
	fun(0, 0);

	return 0;
}