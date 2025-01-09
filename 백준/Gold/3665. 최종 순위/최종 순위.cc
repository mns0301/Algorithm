#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

    priority_queue<pair<int, int>> pq;

    for (int i = 1; i <= n; i++) {
        pq.push({ -degree[i], i });
    }

    int pre_deg = 0;
    for (int i = 1; i <= n; i++) {
        int now = pq.top().second;
        int now_deg = -pq.top().first;
        pq.pop();

        if (pre_deg == now_deg)
            break;
        else {
            pre_deg = now_deg;
            rank[i] = now;
        }
    }

    if (pq.empty()) {
        for (int i = 1; i <= n; i++)
            cout << rank[i] << " ";
        cout << "\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
    }

    return;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) fun();

    return 0;
}