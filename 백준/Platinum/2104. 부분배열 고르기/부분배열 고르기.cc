#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void seg_make_min(vector<long long>& v, vector<long long>& seg, int node, int s, int e) {
	if (s == e) {
		seg[node] = s;
		return;
	}
	seg_make_min(v, seg, node * 2, s, (s + e) / 2);
	seg_make_min(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
	seg[node] = (v[seg[node * 2]] > v[seg[node * 2 + 1]]) ? seg[node * 2 + 1] : seg[node * 2];
}

void seg_make_val(vector<long long>& v, vector<long long>& seg, int node, int s, int e) {
	if (s == e) {
		seg[node] = v[s];
		return;
	}
	seg_make_val(v, seg, node * 2, s, (s + e) / 2);
	seg_make_val(v, seg, node * 2 + 1, (s + e) / 2 + 1, e);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int seg_find_min(vector<long long>& v, vector<long long>& seg, int node, int s, int e, int l, int r) {
	if (s > r || e < l) return -1;
	if (l <= s && e <= r) return seg[node];

	int ll = seg_find_min(v, seg, node * 2, s, (s + e) / 2, l, r);
	int rr = seg_find_min(v, seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
	if (ll == -1) return rr;
	if (rr == -1) return ll;
	return (v[ll] < v[rr]) ? ll : rr;
}

long long seg_find_val(vector<long long>& seg, int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	else return seg_find_val(seg, node * 2, s, (s + e) / 2, l, r) + seg_find_val(seg, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

long long Score(vector<long long>& v, vector<long long>& seg_min, vector<long long>& seg_val, int s, int e) {
	if (s > e) return 0;
	
	int index = seg_find_min(v, seg_min, 1, 0, v.size() - 1, s, e);
	long long t = seg_find_val(seg_val, 1, 0, v.size() - 1, s, e);
	long long ans = t * v[index];

	long long l = Score(v, seg_min, seg_val, s, index - 1);
	long long r = Score(v, seg_min, seg_val, index + 1, e);	
	return max(ans, max(l, r));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<long long> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	int sz = (int)(ceil(log2(n))) + 1;
	vector<long long> seg_min(1 << sz, 0);
	vector<long long> seg_val(1 << sz, 0);
	seg_make_min(v, seg_min, 1, 0, n - 1);
	seg_make_val(v, seg_val, 1, 0, n - 1);

	long long ans = Score(v, seg_min, seg_val, 0, n - 1);

	cout << ans;
	return 0;
}