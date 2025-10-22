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
#include <random>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int dy8[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx8[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy4[4] = { -1, 0, 1, 0 };
int dx4[4] = { 0, 1, 0, -1 };

vpll v(100000);
int n;

bool cross(pll x, pll y, pll z) {
    pll v = { x.first - y.first, x.second - y.second };
    pll w = { y.first - z.first, y.second - z.second };
    return v.first * w.second - v.second * w.first;
}

bool fun(int a, int b) {
    vpll l1, l2;
    for (int i = 0; i < n; i++) {
    	if (!cross(v[a], v[b], v[i])) {
            l1.push_back(v[i]);
        }
    	else {
            l2.push_back(v[i]);
        }
    }
    if (l2.size() > 2) {
        for (int i = 2; i < l2.size(); i++) {
    		if (cross(l2[0], l2[1], l2[i]))
                return 0;
        }
    }
    return 1;
}

int main() {
	fastio;

    cin >> n;
	f(i, n) {
        ll x, y;
        cin >> x >> y;
        v[i] = { x, y };
    }
	if (n <= 4) {
        cout << "success\n";
        return 0;
    }
    srand(0);

    for (int i = 0; i < 100; i++) {
        int a = rand()%n;
    	int b = rand()%n;
		while(a==b)
			b = rand()%n;

		if (fun(a,b)) {
            cout << "success\n";
            return 0;
        }
    }
    cout << "failure\n";
    return 0;
}