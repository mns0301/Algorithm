#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
    fastio;

    int n, m, t = 0;
    cin >> n >> m;
    vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> visited(n + 2, vector<int>(m + 2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    pq.push({ 0, 1, 1 });
    visited[1][1] = 2;

    for (int i = 0; i < n + 2; i++) {
        visited[i][0] = 2;
        visited[i][m + 1] = 2;
    }
    for (int i = 0; i < m + 2; i++) {
        visited[0][i] = 2;
        visited[n + 1][i] = 2;
    }

    while (pq.size())
    {
        auto [time, x, y] = pq.top();
        pq.pop();
        t = time;

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i], xx = x + dx[i];

            if (visited[yy][xx] == 2)
                continue;

            if (v[yy][xx] == 1) {
                if (visited[yy][xx] == 0)
                    visited[yy][xx] = 1;
                else {
                    visited[yy][xx] = 2;
                    pq.push({ time + 1, xx, yy });
                }
            }
            else {
                visited[yy][xx] = 2;
                pq.push({ time, xx, yy });
            }
        }
    }

    cout << t;
    return 0;
}