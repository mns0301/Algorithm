#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<vector<int>> v(n + 1, vector<int>(n + 1, 1e9));
        for (int i = 1; i <= n; i++) v[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            v[t1][t2] = min(v[t1][t2], t3);
            v[t2][t1] = min(v[t2][t1], t3);
        }

        for (int i = 0; i < w; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            v[t1][t2] = min(v[t1][t2], -t3);
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }

        int i = 1;
        for (i; i <= n; i++) {
            if (v[i][i] < 0) {
                cout << "YES\n";
                break;
            }
        }
        if (i == n + 1) cout << "NO\n";
    }

    return 0;
}