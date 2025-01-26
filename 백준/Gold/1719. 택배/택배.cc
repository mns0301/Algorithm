#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 1e9));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = w;
        graph[v2][v1] = w;
    }

    for (int i = 0; i <= n; i++) {
        graph[i][i] = 0;
        for (int j = 0; j <= n; j++)
            ans[i][j] = j;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;

                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i==j)
                cout << "- ";
            else
                cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

        return 0;
}