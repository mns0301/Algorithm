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

    int n, s, e, m;
    cin >> n >> s >> e >> m;
    vector<vpii> v(n);
    vl dist(n, -1e18), earn(n, 0);
    for (int i = 0; i < m; i++) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        v[v1].push_back({ v2, -c });
    }
    for (int i = 0; i < n; i++)
        cin >> earn[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            v[i][j].second += earn[v[i][j].first];
        }
    }

    for (auto [i, cost] : v[s]) {
        dist[i] = cost;
    }
    dist[s] = earn[s];

    for (int loop = 1; loop < n; loop++) {
        for (int i = 0; i < n; i++) {
            if (dist[i] == -1e18)
                continue;

            for (auto [cur, cost] : v[i]) {
                if (dist[cur] < dist[i] + cost) {
                    dist[cur] = dist[i] + cost;
                }
            }
        }
    }

    if (dist[e] == -1e18) {
        cout << "gg";
        return 0;
    }

    queue<int> q;
    vi visited(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (dist[i] == -1e18)
            continue;
        for (auto [cur, cost] : v[i]) {
            if (dist[cur] < dist[i] + cost) {
                q.push(cur);
                visited[cur] = 1;
            }
        }
    }

    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == e) {
            cout << "Gee";
            return 0;
        }

        for (auto [nxt, x] : v[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }

    cout << dist[e];
    return 0;
}