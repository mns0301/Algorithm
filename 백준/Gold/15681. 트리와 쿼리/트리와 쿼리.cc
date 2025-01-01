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

int n, r, q;
vvi graph;
vi visited, cnt;

int dfs(int now) {
    if (visited[now] != 0)
        return 0;

    int w = 1;
    visited[now] = 1;

    for (auto nxt : graph[now]) {
        if (visited[nxt] == 0) {
            w += dfs(nxt);
        }
    }
    return cnt[now] = w;
}

int main() {
    fastio;

    cin >> n >> r >> q;
    
    graph.resize(n + 1);
    visited.resize(n + 1);
    cnt.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(r);

    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << cnt[u] << "\n";
    }


    return 0;
}