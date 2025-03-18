#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n, m, k, s, e;
    cin >> n >> m >> k >> s >> e;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 1e9));
    vector<int> max_w(n + 1, 1e9);
    vector<int> p(k + 1, 0);

    for (int i = 0; i < m; i++) {
        int t0, t1, t2;
        cin >> t0 >> t1 >> t2;
        graph[t0].push_back({ t1, t2 });
        graph[t1].push_back({ t0, t2 });
    }
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    pq.push({ 0, 0, s });
    visited[s][0] = 0;

    while (pq.size()) {
        auto [w, edge, now] = pq.top();
        pq.pop();

        if (visited[now][edge] < w) continue;
        if (now == e) continue;
        if (edge >= n) continue;

        for (auto [nxt, ww] : graph[now]) {
            int weight = w + ww;
            if (visited[nxt][edge + 1] <= weight) continue;
            // if (edge != 0 && visited[nxt][edge - 1] == w - ww) {
            //     continue;
            //     visited[nxt][edge + 1] = w;
            // }
            pq.push({ weight, edge + 1, nxt });
            visited[nxt][edge + 1] = weight;
        }
    }

    int tax = 0;
    for (int i = 0; i <= k; i++) {
        int ans = 1e9;
        for (int j = 1; j <= n; j++) {
            ans = min(j * tax + visited[e][j], ans);
        }
        cout << ans << "\n";
        tax += p[i];
    }

        return 0;
}