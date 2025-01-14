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

int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main() {
    fastio;

    int n;
    cin >> n;
    vpii path(n);
    for (int i = 0; i < n; i++)
        cin >> path[i].first >> path[i].second;
    sort(path.begin(), path.end());

    int sp = path[0].first, ep = path[0].second;
    int mp = ep + ep - sp;

    int i = 1;
    while (i < n) {
        if (path[i].first <= ep) {
            ep = max(ep, path[i].second);
        }
        else if (path[i].first <= mp) {
            sp = path[i].first;
            ep = path[i].second;
        }
        else {
            break;
        }
        i++;
        mp = max(mp, ep + ep - sp);
    }
    cout << ep;

    return 0;
}