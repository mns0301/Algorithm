#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int fun(int n) {
    vector<vector<int>> graph(n + 2, vector<int>(n + 2, -1));
    vector<vector<int>> visited(n + 2, vector<int>(n + 2, 1e9));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({ graph[1][1], 1, 1 });
    visited[1][1] = graph[1][1];

    while (pq.size()) {
        auto [w, y, x] = pq.top();
        pq.pop();

        if (visited[y][x] < w) continue;
        if (y == n && x == n)
            return w;

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            int ww = w + graph[yy][xx];
            if (graph[yy][xx] != -1 && visited[yy][xx] > ww) {
                visited[yy][xx] = ww;
                pq.push({ ww, yy, xx });
            }
        }
    }
    
}

int main() {
    fastio;

    int i = 0;
    while (1) {
        i++;
        int n;
        cin >> n;
        if (n == 0)
            break;
        cout << "Problem " << i << ": " << fun(n) << "\n";
    }

    return 0;
}