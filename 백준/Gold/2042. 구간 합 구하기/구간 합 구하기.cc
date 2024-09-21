#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> seg(4000004);
vector<long long> v(1000001);

long long make_segtree(int node, int s, int e) {
    if (s == e) return seg[node] = v[s];

    int mid = (s + e) / 2;
    long long left = make_segtree(node * 2, s, mid);
    long long right = make_segtree(node * 2 + 1, mid + 1, e);
    seg[node] = left + right;

    return seg[node];
}

long long sum_segtree(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return seg[node];

    int mid = (s + e) / 2;
    long long left = sum_segtree(node * 2, s, mid, l, r);
    long long right = sum_segtree(node * 2 + 1, mid + 1, e, l, r);

    return left + right;
}

void update_segtree(int node, int s, int e, int index, long long val) {
    if (index < s || index > e) return;
    if (s == e) {
        v[index] = val;
        seg[node] = val;
        return;
    }
    int mid = (s + e) / 2;
    update_segtree(node * 2, s, mid, index, val);
    update_segtree(node * 2 + 1, mid + 1, e, index, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> v[i];
    make_segtree(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        int t1;
        cin >> t1;
        if (t1 == 1) {
            int t2;
            long long t3;
            cin >> t2 >> t3;
            update_segtree(1, 1, n, t2, t3);
        } else {
            int t2, t3;
            cin >> t2 >> t3;
            cout << sum_segtree(1, 1, n, t2, t3) << "\n";
        }
    }
    return 0;
}