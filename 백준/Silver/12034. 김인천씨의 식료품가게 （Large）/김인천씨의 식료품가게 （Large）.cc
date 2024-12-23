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

int main() {
    fastio;

    int t;
    cin >> t;
    f1(x, t) {
        int n;
        cin >> n;
        n *= 2;
        vl v(n, 0);
        f(i, n) cin >> v[i];

        queue<ll> s;
        cout << "Case #" << x << ": ";

        for (int i = 0; i < n; i++) {
            if (s.size() && s.front() == v[i] * 3 / 4) {
                cout << s.front() << " ";
                s.pop();
            }
            else {
                s.push(v[i]);
            }
        }

        cout << "\n";
    }

    return 0;
}