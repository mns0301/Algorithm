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

#define INT_MAX 2147483647
#define INT_MIN -2147483648
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

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    priority_queue<pii> pq;
    f(i, k) pq.push({ 0, -i });
    ll ans = 0;
    ll cnt = 1;

    vector<vpii> v(k);
    f(i, n) {
        pii now;
        cin >> now.first >> now.second;
        pii tmp = pq.top();
        pq.pop();
        v[-tmp.second].push_back(now);
        pq.push({ tmp.first - now.second, tmp.second });
    }

    vi idx(k, 0);
    while (1) {
        for (int i = k - 1; i >= 0; i--) {
            if (idx[i] == v[i].size()) continue;
            int now = --v[i][idx[i]].second;

            if (now == 0) {
                ans += cnt * v[i][idx[i]].first;
                idx[i]++;
                cnt++;
            }
        }

        if (cnt == n + 1)
            break;
    }

    cout << ans;

    return 0;
}