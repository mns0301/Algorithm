#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define str string
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)

int n, t, k, m = INT_MIN;

int main() {
	fastio;

	cin >> n;
	f(i, n) {
		cin >> t;
		k += t;
		m = max(m, k);
		k = max(k, 0);
	}

	cout << m;

	return 0;
}