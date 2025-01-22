#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int dy8[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx8[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy4[4] = { -1, 0, 1, 0 };
int dx4[4] = { 0, 1, 0, -1 };

int main() {
    fastio;

    int n;
    cin >> n;
    int cls = 0;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = { y, z };
    }
    sort(v.begin(), v.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ v[0].second, 0 });

    for (int i = 1; i < n; i++) {
        auto [end, c] = pq.top();
        if (end <= v[i].first) {
            pq.pop();
            pq.push({ v[i].second, c });
        }
        else {
            pq.push({ v[i].second, ++cls });
        }
    }

    cout << pq.size();

    return 0;
}