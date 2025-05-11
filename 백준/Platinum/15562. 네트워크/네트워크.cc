#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> deg(1000001);

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]--;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 0)
            ans += deg[i];
    }
    cout << ans;
}