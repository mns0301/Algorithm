#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void seg_make(vector<int>& v, vector<int>& seg, int node, int s, int e) {
    if (s == e) {
        seg[node] = v[s];
        return;
    } else {
        seg_make(v, seg, node * 2, s, (s + e) / 2);
        seg_make(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
        seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
    }
}

int find(vector<int>& seg, int node, int s, int e, int l, int r) {
    if (s > r || e < l) return 1e9;
    if (l <= s && e <= r) return seg[node];
    return min(find(seg, node * 2, s, (s + e) / 2, l, r), find(seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    vector<int> seg(4 * n + 1, 1e9);
    for (int i = 0; i < n; i++) cin >> v[i];
    seg_make(v, seg, 1, 0, n - 1);

    int t1, t2;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        t1--;
        t2--;
        cout << find(seg, 1, 0, n - 1, t1, t2) << "\n";
    }

    return 0;
}