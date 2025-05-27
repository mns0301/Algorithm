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

int main() {
    fastio;

    int n, m, s, e;
    cin >> n >> m;

    vector<vpii> v(n + 1);
    vi visited(n + 1, 1e9);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({ b, w });
    }
    cin >> s >> e;

    visited[s] = 0;
    priority_queue<pii> pq;
    pq.push({ 0, s });

    while (1) {
        auto [w, cur] = pq.top();
        pq.pop();

        if (visited[cur] < -w) continue;
        if (cur == e) break;

        for (auto [nxt, cost] : v[cur]) {
            cost = cost - w;
            if (visited[nxt] > cost) {
                visited[nxt] = cost;
                pq.push({ -cost, nxt });
            }
        }
    }

    cout << visited[e];

    return 0;
}