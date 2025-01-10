#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void fun() {
    int n, m;
    cin >> n;
    vector<int> rank(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        rank[x] = i;
    }
    cin >> m;
    vector<int> degree(rank);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (rank[x] < rank[y]) {
            degree[x]++;
            degree[y]--;
        }
        else {
            degree[x]--;
            degree[y]++;
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) ans.push_back({ degree[i], i });
    sort(ans.begin(), ans.end());

    int pre = 0, flag = 1;
    for (int i = 0; i < n; i++) {
        if (pre == ans[i].first) {
            flag = 0;
            break;
        }
        pre = ans[i].first;
        rank[i] = ans[i].second;
    }

    if (flag) {
        for (int i = 0; i < n; i++)
            cout << rank[i] << " ";
        cout << "\n";
    }
    else
        cout << "IMPOSSIBLE\n";

    return;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) fun();

    return 0;
}