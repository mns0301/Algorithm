#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> visited(500001, vector<int>(2, -1));
    queue<array<int, 3>> q;
    q.push({ 0, n, k });
    visited[n][0] = 0;
    int max_time = 0;
    while (max_time*(max_time + 1) <= 1000000 - 2 * k) {
        max_time++;
    }

        while (q.size())
        {
            auto [time, now, end] = q.front();
            q.pop();

            // if (now == end)
            //     break;
            if (max_time == time)
                break;

            if (now < 500000 && visited[now + 1][(time + 1) % 2] == -1) {
                visited[now + 1][(time + 1) % 2] = time + 1;
                q.push({ time + 1, now + 1, end + time + 1 });
            }
            if (now > 0 && visited[now - 1][(time + 1) % 2] == -1) {
                visited[now - 1][(time + 1) % 2] = time + 1;
                q.push({ time + 1, now - 1, end + time + 1 });
            }
            if (now <= 250000 && visited[now * 2][(time + 1) % 2] == -1) {
                visited[now * 2][(time + 1) % 2] = time + 1;
                q.push({ time + 1, now * 2, end + time + 1 });
            }
        }

        int ans = 9999;
        int i = k;

        for (int t = 0; t < max_time; t++) {
            i += t;
            if (i > 500000)
                break;

            if (visited[i][t % 2] != -1 && visited[i][t % 2] <= t) {
                // ans = min(ans, visited[i][t % 2]);
                ans = min(ans, t);
            }
        }

        cout << (ans == 9999 ? -1 : ans);

        return 0;
}