#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <time.h>
#include <vector>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while (t--)
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)

vpll v(100000);
int n, p;

bool cross(pll x, pll y, pll z) {
    pll v = { x.first - y.first, x.second - y.second };
    pll w = { y.first - z.first, y.second - z.second };
    return v.first * w.second - v.second * w.first;
}

int fun(int a, int b) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!cross(v[a], v[b], v[i])) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    fastio;

    cin >> n >> p;
    f(i, n) {
        ll x, y;
        cin >> x >> y;
        v[i] = { x, y };
    }
    // srand(time(0));
    srand(0);
	if (n <= 2) {
        cout << "possible\n";
        return 0;
    }

    for (int i = 0; i < 200; i++) {
        int a = rand() % n;
        int b = rand() % n;
        while (a == b)
            b = rand() % n;

        if (fun(a, b) * 100 >= n * p) {
            cout << "possible\n";
            return 0;
        }
    }
    cout << "impossible\n";
    return 0;
}