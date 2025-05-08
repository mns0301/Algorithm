#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

int main() {
    fastio;

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }

    queue<pair<int, int>> q;
    vector<bool> visited(1000001, false);
    q.push({ n, 0 });
    visited[n] = true;

    while (!q.empty()) {
        auto [num, lev] = q.front();
        q.pop();

        if (num == 1) {
            cout << lev;
            break;
        }

        if (num % 2 == 0 && !visited[num / 2]) {
            q.push({ num / 2, lev + 1 });
            visited[num / 2] = true;
        }
        if (num % 3 == 0 && !visited[num / 3]) {
            q.push({ num / 3, lev + 1 });
            visited[num / 3] = true;
        }
        if (!visited[num - 1]) {
            q.push({ num - 1, lev + 1 });
            visited[num - 1] = true;
        }
    }
    return 0;
}