#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void seg_make(vector<long long>& v, vector<long long>& seg, int node, int s, int e) {
	if (s == e) seg[node] = v[s];
	else {
		seg_make(v, seg, node * 2, s, (s + e) / 2);
		seg_make(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
		seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
	}
}

void seg_lazy(vector<long long>& seg, vector<long long>& lazy, int node, int s, int e) {
	if (lazy[node] != 0) {
		seg[node] ^= ((e - s + 1) % 2) * lazy[node];
		if (s != e) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void seg_update(vector<long long>& seg, vector<long long>& lazy, int node, int s, int e, int l, int r, long long dif) {
	seg_lazy(seg, lazy, node, s, e);
	if (l > e || r < s) return;
	if (l <= s && e <= r) {
		seg[node] ^= ((e - s + 1) % 2) * dif;
		if (s != e) {
			lazy[node * 2] ^= dif;
			lazy[node * 2 + 1] ^= dif;
		}
		return;
	}
	seg_update(seg, lazy, node * 2, s, (s + e) / 2, l, r, dif);	
	seg_update(seg, lazy, node * 2 + 1, (s + e) / 2 + 1, e, l, r, dif);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

long long seg_find(vector<long long>& seg, vector<long long>& lazy, int node, int s, int e, int l, int r) {
	seg_lazy(seg, lazy, node, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	return seg_find(seg, lazy, node * 2, s, (s + e) / 2, l, r) ^ seg_find(seg, lazy, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;
	vector<long long> v(n, 0);
	int size = (int)ceil(log2(n));
	vector<long long> seg(1 << (size + 1), 0);
	vector<long long> lazy(1 << (size + 1), 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	seg_make(v, seg, 1, 0, n - 1);
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t1;
		cin >> t1;
		if (t1 == 1) {
			int t2, t3;
			long long t4;
			cin >> t2 >> t3 >> t4;
			seg_update(seg, lazy, 1, 0, n - 1, t2, t3, t4);
		}
		else {
			int t2;
			cin >> t2;
			cout << seg_find(seg, lazy, 1, 0, n - 1, t2, t2) << "\n";
		}
	}

	return 0;
}