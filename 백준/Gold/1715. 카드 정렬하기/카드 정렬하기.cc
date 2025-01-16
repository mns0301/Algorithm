#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pq.push(t);
    }
    while (pq.size() != 1) {
        int t1, t2;
        t1 = pq.top();
        pq.pop();
        t2 = pq.top();
        pq.pop();
        pq.push(t1 + t2);
        ans += t1 + t2;
    }
    cout << ans;

    return 0;
}