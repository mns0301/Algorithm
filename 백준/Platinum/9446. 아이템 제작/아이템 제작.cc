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
// #define ll long long
#define int long long
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

int n, m;
vector<vector<pair<int, int>>> graph; // <with, target>
vector<int> weight;
priority_queue<pair<int, int>> pq;

signed main() {
	fastio;

    cin >> n >> m;
    graph.resize(n + 1);
    weight.resize(n + 1);
    f1(i, n) cin >> weight[i];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[b].push_back({ c, a });
        graph[c].push_back({ b, a });
        pq.push({ -(weight[b] + weight[c]), a });
    }

    while(pq.size()) {
        int w = -pq.top().first;
        int target = pq.top().second;
        pq.pop();
        // cout << target << ", w: " << w << "\n";
        if (weight[target] < w) 
            continue;
        weight[target] = w;

        for (auto [with, nxt] : graph[target]) {
            int nxt_w = weight[target] + weight[with];
            if (nxt_w < weight[nxt]) {
                // cout << "push: (" << target << ", " << nxt_w << ")\n";
                pq.push({ -nxt_w, nxt });
                weight[nxt] = nxt_w;
            }
        }
    }
    cout << weight[1];

    return 0;
}