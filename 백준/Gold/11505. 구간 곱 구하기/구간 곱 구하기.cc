#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void seg_make(vector<long long>& v, vector<long long>& seg, int node, int s, int e) {
    if (s == e) {
        seg[node] = v[s];
        return;
    } else {
        seg_make(v, seg, node * 2, s, (s + e) / 2);
        seg_make(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
        seg[node] = seg[node * 2] * seg[node * 2 + 1] % 1000000007;
        return;
    }
}

long long seg_find(vector<long long>& seg, int node, int s, int e, int l, int r) {
    if (s > r || e < l) return 1;
    if (l <= s && e <= r) {
        return seg[node];
    }
    return seg_find(seg, node * 2, s, (s + e) / 2, l, r) * seg_find(seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r) % 1000000007;
}

void seg_update(vector<long long>& v, vector<long long>& seg, int node, int s, int e, int index, int val) {
    if (index < s || index > e) return;
    if (s == e) {
        v[index] = val;
        seg[node] = val;
        return;
    } else {
        seg_update(v, seg, node * 2, s, (s + e) / 2, index, val);
        seg_update(v, seg, node * 2 + 1, (s + e) / 2 + 1, e, index, val);
        seg[node] = seg[node * 2] * seg[node * 2 + 1] % 1000000007;
        return;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> v(n + 1, 0);
    vector<long long> seg(4 * n + 1, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    seg_make(v, seg, 1, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        int t1;
        cin >> t1;
        if (t1 == 1) {
            int t2;
            long long t3;
            cin >> t2 >> t3;
            t2--;
            seg_update(v, seg, 1, 0, n - 1, t2, t3);
        } else {
            int t2, t3;
            cin >> t2 >> t3;
            t2--;
            t3--;
            cout << seg_find(seg, 1, 0, n - 1, t2, t3) << "\n";
        }
    }

    return 0;
}