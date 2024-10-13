#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <deque>
#include <cmath>
using namespace std;

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
#define f(i, n) for(int i = 0; i < n; i++)

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        ll p = 1, s = 1;
        n = min(n, m - n);
        while (n) {
            p *= m--;
            if (p%n == 0) p /= n--;
            else s *= n--;
        }
        p /= s;

        cout << p << "\n";
    }


    return 0;
}