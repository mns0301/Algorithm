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

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    fastio;

    int n;
    cin >> n;
    vpii v(n);
    f(i, n) {
        int t;
        cin >> t;
        v[i] = { t, i };
    }
    sort(v.begin(), v.end());
    int t = 0;
    f(i, n) {
        v[i].first = t++;
    }
    sort(v.begin(), v.end(), compare);
    for (auto [c, _] : v) {
        cout << c << " ";
    }

        return 0;
}