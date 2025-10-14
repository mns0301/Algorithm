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

int main() {
    fastio;

    int n;
    cin >> n;
    vector<pii> v(n);
    f(i, n) cin >> v[i].first >> v[i].second;

    int s = 1e9, ans_i = 0;
    for (int start = v[0].first; start <= v[0].second; start++) {
        int cur = start, tmp = 0;

        for (int i = 1; i < n; i++) {
            if (v[i].first > cur) {
                tmp += v[i].first - cur;
                cur = v[i].first;
            }
            else if (v[i].second < cur) {
                tmp += cur - v[i].second;
                cur = v[i].second;
            }
        }
        if (tmp < s) {
            ans_i = start;
            s = tmp;
        }
    }
    cout << s << "\n" << ans_i << "\n";
    for (int i = 1; i < n; i++) {
        if (v[i].first > ans_i) ans_i = v[i].first;
        else if (v[i].second < ans_i) ans_i = v[i].second;
        cout << ans_i << "\n";
    }

    return 0;
}