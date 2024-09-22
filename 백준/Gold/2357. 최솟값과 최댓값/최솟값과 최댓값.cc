#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void seg_min_make(vector<int>& v, vector<int>& seg, int node, int s, int e) {
	if (s == e) {
		seg[node] = v[s];
		return;
	}
	seg_min_make(v, seg, node * 2, s, (s + e) / 2);
	seg_min_make(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
	seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

void seg_max_make(vector<int>& v, vector<int>& seg, int node, int s, int e) {
	if (s == e) {
		seg[node] = v[s];
		return;
	}
	seg_max_make(v, seg, node * 2, s, (s + e) / 2);
	seg_max_make(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
	seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

int seg_min_find(vector<int>& seg, int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 1e9;
	if (l <= s && e <= r) return seg[node];
	return min(seg_min_find(seg, node * 2, s, (s + e) / 2, l, r), seg_min_find(seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int seg_max_find(vector<int>& seg, int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	return max(seg_max_find(seg, node * 2, s, (s + e) / 2, l, r), seg_max_find(seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	vector<int> seg_min(4 * n, 0);
	vector<int> seg_max(4 * n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	seg_min_make(v, seg_min, 1, 0, n - 1);
	seg_max_make(v, seg_max, 1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		cout << seg_min_find(seg_min, 1, 0, n - 1, t1 - 1, t2 - 1) << " " << seg_max_find(seg_max, 1, 0, n - 1, t1 - 1, t2 - 1) << "\n";
	}

	return 0;
}