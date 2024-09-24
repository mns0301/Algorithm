#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void init(vector<int>& v, vector<int>& seg, int node, int s, int e) {
	if (s == e) {
		seg[node] = v[s];
		return;
	}
	init(v, seg, node * 2, s, (s + e) / 2);
	init(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
	seg[node] = seg[node * 2] * seg[node * 2 + 1];
}

void seg_update(vector<int>& v, vector<int>& seg, int node, int s, int e, int index, int val) {
	if (index > e || index < s) return;
	if (s == e) {
		v[index] = val;
		seg[node] = val;
		return;
	}
	seg_update(v, seg, node * 2, s, (s + e) / 2, index, val);
	seg_update(v, seg, node * 2 + 1, (s + e) / 2 + 1, e, index, val);
	seg[node] = seg[node * 2] * seg[node * 2 + 1];
}

int seg_find(vector<int>& seg, int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 1;
	if (l <= s && e <= r) return seg[node];
	return seg_find(seg, node * 2, s, (s + e) / 2, l, r) * seg_find(seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	while(cin >> n >> k) {
		vector<int> v(n, 0);
		vector<int> seg(1 << (int)(ceil(log2(n)) + 1), 0);

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			if (temp > 0) v[i] = 1;
			else if (temp < 0) v[i] = -1;
			else v[i] = 0;
		}
		init(v, seg, 1, 0, n - 1);

		for (int i = 0; i < k; i++) {
			char order;
			cin >> order;
			if (order == 'C') {
				int t1, t2;
				cin >> t1 >> t2;
				if (t2 > 0) t2 = 1;
				else if (t2 < 0) t2 = -1;
				else t2 = 0;
				seg_update(v, seg, 1, 0, n - 1, t1 - 1, t2);
			}
			else {
				int t1, t2;
				cin >> t1 >> t2;
				int temp = seg_find(seg, 1, 0, n - 1, t1 - 1, t2 - 1);
				if (temp == 1) cout << "+";
				else if (temp == -1) cout << "-";
				else cout << "0";
			}
		}
		cout << "\n";
	}

	return 0;
}