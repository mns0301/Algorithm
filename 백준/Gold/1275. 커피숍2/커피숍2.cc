#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void seg_make(vector<long long>& v, vector<long long>& seg, int node, int s, int e) {
	if (s == e) {
		seg[node] = v[s];
		return;
	}
	seg_make(v, seg, node * 2, s, (s + e) / 2);
	seg_make(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long long seg_find(vector<long long>& seg, int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	return seg_find(seg, node * 2, s, (s + e) / 2, l, r) + seg_find(seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

void seg_update(vector<long long>& v, vector<long long>& seg, int node, int s, int e, int i, int val) {
	if (i < s || e < i) return;
	if (s == e) {
		v[i] = val;
		seg[node] = val;
		return;
	}
	seg_update(v, seg, node * 2, s, (s + e) / 2, i, val);
	seg_update(v, seg, node * 2 + 1, (s + e) / 2 + 1, e, i, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<long long> v(n, 0);
	vector<long long> seg(4 * n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	seg_make(v, seg, 1, 0, n - 1);

	for (int i = 0; i < q; i++) {
		int t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		if (t1 > t2) swap(t1, t2);
		cout << seg_find(seg, 1, 0, n - 1, t1 - 1, t2 - 1) << "\n";
		seg_update(v, seg, 1, 0, n - 1, t3 - 1, t4);
	}

	return 0;
}