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

int parent[1000001];

int search(int x) {
	if (parent[x] == x)
        return x;
    return parent[x] = search(parent[x]);
}

void Union(int u, int v) {
    u = search(u), v = search(v);
    parent[v] = u;
}

int main() {
	fastio;

    int t;
    cin >> t;

	f1(r, t) {
        cout << "Scenario " << r << ":\n";
        int n, k;
        cin >> n >> k;
        f(i, n) parent[i] = i;
		w(k) {
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }

        int m;
        cin >> m;
		w(m) {
            int a, b;
            cin >> a >> b;
            if (search(a) == search(b))
                cout << "1\n";
			else
                cout << "0\n";
        }
        cout << "\n";
    }	

    return 0;
}