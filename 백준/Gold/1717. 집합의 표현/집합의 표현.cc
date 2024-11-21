#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
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

int parent[1000001];

int Find(int x) {
	if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    parent[u] = v;
}

int main() {
	fastio;

    int n, m;
    cin >> n >> m;
    f(i, n+1) parent[i] = i;

	w(m) {
        int order, a, b;
        cin >> order >> a >> b;

		if (order) {
            cout << (Find(a) == Find(b) ? "YES" : "NO") << "\n";
        }
		else {
            Union(a, b);
        }
    }

    return 0;
}