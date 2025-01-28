#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        int t = 0;
        for (int j = 0; j < m; j++) {
            t += abs(v[i][j] - v[0][j]);
        }
        if (t > 2000)
            cnt--;
        else
            cnt++;
    }

    cout << (cnt > 0 ? "NO" : "YES");
    
    return 0;
}