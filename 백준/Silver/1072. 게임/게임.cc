#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while (t--)
#define f(i, n) for (int i = 0; i < n; i++)

int main()
{
	fastio;

	double x, y, z;
	cin >> x >> y;
	ll i = 0;
	ll ans = 0;
	z = floor(100 * y / x);

	for (i = 0; i < INT_MAX; i += 100)
	{
		if (floor(100 * (y + i) / (x + i)) > z)
		{
			break;
		}
	}

	if (i > INT_MAX)
		cout << -1;
	else {
		for (ll j = 0; j <= 100; j++) {
			if ((floor(100 * (y + i - j) / (x + i - j)) > z))
			{
				ans = i - j;
			}
		}
		cout << ans;
	}

		return 0;
}