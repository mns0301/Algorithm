#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = { y, z };
    }
    sort(v.begin(), v.end());
    priority_queue<int> pq;
    pq.push(-v[0].second);

    for (int i = 1; i < n; i++) {
        if (-pq.top() <= v[i].first)
            pq.pop();
        pq.push(-v[i].second);
    }

    cout << pq.size();

    return 0;
}