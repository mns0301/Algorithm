#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define str string
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)

void input();
void fun();

int n, m;
vi vec;
vi tree;

void init(int s, int e, int node) {
	if (s==e) tree[node] = s;
	else {
		init(s, (s + e) / 2, node * 2);
		init((s+e) / 2 + 1, e, node * 2 + 1);
		tree[node] = (vec[tree[node * 2]] <= vec[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1]);
	}
}

void update(int s, int e, int node, int idx, int v) {
	if (idx < s || e < idx) return;
	if (s==e) {
		vec[idx] = v;
		tree[node] = idx;
		return;
	}
	update(s, (s + e) / 2, node * 2, idx, v);
	update((s + e) / 2 + 1, e, node * 2 + 1, idx, v);
	tree[node] = (vec[tree[node * 2]] <= vec[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1]);
}

int query(int s, int e, int l, int r, int node) {
	if (s > r || e < l) return l;
	if (l <= s && e <= r) return tree[node];
	int left = query(s, (s + e) / 2, l, r, node * 2);
	int right = query((s + e) / 2 + 1, e, l, r, node * 2 + 1);
	return (vec[left] <= vec[right] ? left : right);
}

void input() {
	cin >> n;
	vec.resize(n);
	tree.resize(4 * n);
	f(i, n) cin >> vec[i];
	cin >> m;
}

void fun() {
	while (m--) {
		int order;
		cin >> order;
		if (order == 1) {
			int i, v;
			cin >> i >> v;
			update(0, n-1, 1, i-1, v);
		}
		else {
			int i, j;
			cin >> i >> j;
			cout << query(0, n-1, i - 1, j - 1, 1) + 1 << "\n";
		}
	}
}
int main() {
	fastio;

	input();
	init(0, n-1, 1);

	fun();

	return 0;
}