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
#define INF 1'000'000'000'000'000'000
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

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> graph(m);
    f(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[i] = { u, v, w };
    }

    vl dist(n + 1, INF);
    dist[1] = 0;

    f(i, n - 1) {
        for (auto [u, v, w] : graph) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto [u, v, w] : graph) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }

        return 0;
}