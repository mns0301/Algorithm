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
#define f1(i, n) for(int i = 1; i <= n; i++)

int parent[201];

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

    f1(i, n) parent[i] = i;

    f1(i, n) {
		f1(j, n) {
            int a;
            cin >> a;
			if (a)
                Union(i, j);
        }
	}

    int cur = -1;
    w(m) {
        int a;
        cin >> a;
		if (cur == -1)
            cur = Find(a);
		else if (cur != Find(a)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}