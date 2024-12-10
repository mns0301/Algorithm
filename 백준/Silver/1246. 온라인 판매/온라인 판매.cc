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

    int n, m;
    cin >> n >> m;
    vi v(m, 0);
    f(i, m) cin >> v[i];
    int cost = 0;
    int idx = 0;
    sort(v.begin(), v.end());

    f(i, m) {
        if (v[i] * min(n, (m - i)) > cost) {
            cost = v[i] * min(n, (m - i));
            idx = v[i];
        }
    }

    cout << idx << " " << cost;

    return 0;
}