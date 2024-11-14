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

#define INT_MAX 2147483647
#define INT_MIN -2147483648
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

set<string> s;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<string>> v(n + 2, vector<string>(m + 2, ""));
    f(i, n) {
        f(j, m) {
            cin >> v[i][j];
        }
    }
    f(i, n) {
        f(j, m) {
            if (v[i][j] == v[i][j+1] || v[i][j] == v[i][j+2] || v[i][j] == v[i+1][j] || v[i][j] == v[i+2][j])
                s.insert(v[i][j]);
        }
    }

    if (s.empty())
        s.insert("MANIPULATED");
    for (auto i : s) {
        cout << i << "\n";
    }
    return 0;
}