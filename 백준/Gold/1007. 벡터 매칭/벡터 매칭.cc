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

// #define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define ld long double
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

ll len(pll a) {
    return a.first * a.first + a.second * a.second;
}

pll recur(int maxdepth, int depth, int i, pll sum, vector<pll> &v) {
    if (i == maxdepth*2)
        return { 1e7, 1e7 };
    if (depth == maxdepth) {
        for (i; i < maxdepth * 2; i++) {
            sum.first -= v[i].first;
            sum.second -= v[i].second;
        }
        return sum;
    }

    pll t1 = sum, t2 = sum;
    t1 = { sum.first - v[i].first, sum.second - v[i].second };
    t1 = recur(maxdepth, depth, i + 1, t1, v);
    t2 = { sum.first + v[i].first, sum.second += v[i].second };
    t2 = recur(maxdepth, depth + 1, i + 1, t2, v);
    return (len(t1) < len(t2) ? t1 : t2);
}

void fun() {
    int n;
    cin >> n;
    vector<pll> v(n);
    f(i, n) cin >> v[i].first >> v[i].second;
    pll pos;
    pos = recur(n / 2, 0, 0, { 0, 0 }, v);
    printf("%llf\n", sqrtl(len(pos)));
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--)
        fun();

    return 0;
}