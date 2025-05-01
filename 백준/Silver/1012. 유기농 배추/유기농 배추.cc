#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define y first
#define x second

pair<int, int> dic[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

void fun() {
    int n, m, k, ans = 0;
    cin >> m >> n >> k;
    vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
    queue<pair<int, int>> s;

    while (k--) {
        int yy, xx;
        cin >> xx >> yy;
        v[yy + 1][xx + 1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j]) {
                s.push({ i, j });
                v[i][j] = 0;
                ans++;
            }
            while (s.size()) {
                pair<int, int> cur = s.front(); // <- 이시키가 빌런임
                s.pop();

                for (pair<int, int> d : dic) {
                    pair<int, int> nxt = { cur.y + d.y, cur.x + d.x };
                    if (v[nxt.y][nxt.x]) {
                        v[nxt.y][nxt.x] = 0;
                        s.push(nxt);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    fastio;

    int t;
    cin >> t;
    while(t--) {
        fun();
    }

    return 0;
}