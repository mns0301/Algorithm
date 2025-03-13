#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

int main() {
	fastio;

    int n, x;
    cin >> n;
    ll N = 100000;
    vector<ll> v(100001, 1), primes;

    for (ll i = 2; i <= N; i++) {
        if (v[i]) {
            primes.push_back(i);
            for (ll j = i * 2; j * j <= N; j += i)
                v[j] = 0;
        }
    }

    while (n--) {
        map<ll, ll> m;
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