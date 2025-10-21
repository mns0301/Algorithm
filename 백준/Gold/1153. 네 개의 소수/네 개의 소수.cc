#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long
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
#define f1(i, n) for(int i = 1; i <= n; i++)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int dy8[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx8[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy4[4] = { -1, 0, 1, 0 };
int dx4[4] = { 0, 1, 0, -1 };

vector<ll> is_prime(1000001, 1);
void pri() {
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (ll i = 2; i < 1000001; i++) {
		if (is_prime[i] == 0) continue;

        for (ll j = i * i; j < 1000001; j+=i) {
            is_prime[j] = 0;
        }
    }
}

int main() {
	fastio;

    int n;
    cin >> n;
    pri();

    if (n < 8) {
        cout << -1;
        return 0;
    }
    if (n & 1)
        cout << 3 << " ";
	else
        cout << 2 << " ";
    cout << "2 ";
    n -= (n & 1 ? 5 : 4);

    // cout << "dd" << n << "dd";
    for (int i = 2; i < 1000001; i++) {
        if (is_prime[i] && is_prime[n-i]) {
            cout << i << " " << n - i;
            break;
        }
    }

        return 0;
}