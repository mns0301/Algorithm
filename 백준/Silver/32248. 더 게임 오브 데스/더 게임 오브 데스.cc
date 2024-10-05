#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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

int main(void) {
    fastio;

    ll n, t;
    cin >> n >> t;
    vl v(n + 1, 0), visit(n + 1, 0), log;
    for (int i = 1; i <= n; i++) cin >> v[i];

    ll T = t;
    ll x = 1;
    ll s, c;
    while (T--) {
        log.push_back(x);
        if (visit[x] == 1) {
            if (log[log.size() - 1] == log[log.size() - 2]) {
				cout << log[log.size() - 1];
                return 0;
            }
            for (int i = 0; i < log.size() - 1; i++) {
                if (log[i] == v[x]) {
                    c = log.size() - i;
                    break;
                }
            }
            s = log.size() - c - 1;

            for (int i = 0; i < log.size(); i++) {
               // cout << log[i] << "\n";
            } 
			//cout << s << " : " << c << "\n";
            break;
        }
        visit[x] = 1;
        x = v[x];
    }

    if (T < 0) {
        cout << x;
        return 0;
    }

    ll index = (t - s) % c + s;
    cout << log[index];

    return 0;
}