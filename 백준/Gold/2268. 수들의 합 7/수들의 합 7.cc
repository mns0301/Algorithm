#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	int n, m;
	cin >> n >> m;
	vector<long long> v(n, 0);
	vector<long long> seg(4 * n, 0);
	
	for (int i = 0; i < m; i++) {
		int t1;
		cin >> t1;
		if (t1) {
			int t2;
			long long t3;
			cin >> t2 >> t3;
			seg_update(v, seg, 1, 0, n - 1, t2 - 1, t3);
		}
		else {
			int t2, t3;
			cin >> t2 >> t3;
			if (t2 > t3) swap(t2, t3);
			cout << seg_find(seg, 1, 0, n - 1, t2 - 1, t3 - 1) << "\n";
		}
	}

	return 0;
}