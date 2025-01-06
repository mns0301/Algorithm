#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m, n;

void fun() {
    vector<vector<pair<int, int>>> graph(m);

    int total = 0;
    for (int i = 0; i < n; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({ e, w });
        graph[e].push_back({ s, w });
        total += w;
    }

    vector<int> visited(m, 0);
    priority_queue<pair<int, int>> pq;
    visited[0] = 1;
    for (auto nxt : graph[0])
        pq.push({ -nxt.second, nxt.first });

    while (pq.size()) {
        int now = pq.top().second;
        int w = -pq.top().first;
        pq.pop();

        if (visited[now] == 1) continue;

        visited[now] = 1;
        total -= w;
        for (auto [nxt, nxt_w] : graph[now]) {
            if (visited[nxt] == 0) {
                pq.push({ -nxt_w, nxt });
            }
        }
    }

    cout << total << "\n";
}

int main() {
    fastio;

    while(1) {
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;

        fun();
    }

    return 0;
}