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

vector<ll> v, v1, v2;
int n;
ll s;
ll ans = 0;
void fun0(vector<ll> &tmp, int st, int en, ll sum) {
    if (st == en) {
        tmp.push_back(sum);
        return;
    }
    fun0(tmp, st + 1, en, sum + v[st]);
    fun0(tmp, st + 1, en, sum);
}

int main() {
    fastio;

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        v.push_back(t);
    }

    fun0(v1, 0, (n + 1) / 2, 0);
    sort(v1.begin(), v1.end());
    fun0(v2, (n + 1) / 2, n, 0);

    for (auto i : v2) 
        ans += upper_bound(v1.begin(), v1.end(), s - i) - lower_bound(v1.begin(), v1.end(), s - i);

    if (s==0)
        ans--;

    cout << ans;

    return 0;
}