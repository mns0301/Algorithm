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

int n, m;
vector<vector<array<ll, 3>>> graph(100001);

ll dijk(ll t) {
    vector<ll> visited(n + 1, 1e18);
    priority_queue<pll> pq;
    pq.push({ -t, 1 });
    visited[1] = t;

    while (pq.size()) {
        ll time = -pq.top().first;
        ll now = pq.top().second;
        pq.pop();

        if (visited[now] < time) continue;

        if (now == n) {
            return 1;
        }

        f(i, graph[now].size()) {
            ll nxt = graph[now][i][0];
            ll weight = time + graph[now][i][1];
            if (visited[nxt] > weight && weight <= graph[now][i][2]) {
                pq.push({ -weight, nxt });
                visited[nxt] = weight;
            }
        }
    }

    return -1;
}

int main() {
    fastio;

    cin >> n >> m;

    f(i, m) {
        ll u, v, d, w;
        cin >> u >> v >> d >> w;
        graph[u].push_back({ v, d, w });
        graph[v].push_back({ u, d, w });
    }

    ll s = 0, e = 1e18;
    ll mid = -1;
    ll tmp = -1;

    while (s <= e) {
        ll mid = (s + e) / 2;
        ll chk = dijk(mid);
        if (chk == -1) {
            e = mid - 1;
        }
        else if (chk == 1) {
            tmp = max(tmp, mid);
            s = mid + 1;
        }
    }

    cout << tmp;
    return 0;
}