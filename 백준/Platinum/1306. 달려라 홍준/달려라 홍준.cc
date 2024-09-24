#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void seg_make(vector<int>& v, vector<int>& seg, int node, int s, int e) {
	if (s == e) {
		seg[node] = v[s];
		return;
	}
	seg_make(v, seg, node * 2, s, (s + e) / 2);
	seg_make(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
	seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

int seg_find(vector<int>& seg, int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	else {
		return max(seg_find(seg, node * 2, s, (s + e) / 2, l, r), seg_find(seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	vector<int> seg(1 << (int)(ceil(log2(n)) + 1), 0);
	seg_make(v, seg, 1, 0, n - 1);
	int repeat = n - m + 1;
	for (int i = m-1; i < repeat; i++) {
		cout << seg_find(seg, 1, 0, n - 1, i - m + 1, i + m - 1) << " ";
	}

	return 0;
}