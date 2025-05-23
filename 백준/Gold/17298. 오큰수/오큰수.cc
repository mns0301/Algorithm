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

    int n;
    cin >> n;
    vi v(n, -1);

    stack<pii> s;

    f(i, n) {
        int tmp;
        cin >> tmp;

        if (s.empty()) {
            s.push({ i, tmp });
        }
        else {
            while(s.size() && s.top().second < tmp) {
                v[s.top().first] = tmp;
                s.pop();
            }
            s.push({ i, tmp });
        }
    }

    f(i, n) cout << v[i] << " ";

    return 0;
}