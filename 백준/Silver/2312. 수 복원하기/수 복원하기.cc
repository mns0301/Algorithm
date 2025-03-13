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
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

int dy8[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx8[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy4[4] = { -1, 0, 1, 0 };
int dx4[4] = { 0, 1, 0, -1 };

ll N = 100000;
vector<ll> v(100001, 1);
vector<ll> primes;

// map<int, int> m;

void prime() {
    for (ll i = 2; i <= N; i++) {
		if (v[i]) {
            primes.push_back(i);
            for (ll j = i * 2; j * j <= N; j+=i) 
                v[j] = 0;
        }
	}
}

int main() {
	fastio;

    int n;
    cin >> n;

    prime();

    while (n--) {
        map<ll, ll> m;
        int x;
        cin >> x;
		for (auto pri : primes) {
			while (x % pri == 0) {
                m[pri]++;
                x /= pri;
            }
		}
		for (auto [f,s] : m) 
            cout << f << " " << s << "\n";
    }
	

    return 0;
}