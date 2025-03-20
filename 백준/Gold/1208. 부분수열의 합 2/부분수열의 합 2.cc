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

vector<ll> v, v2;
ll a1[5000001];
int n;
ll s;
ll ans = 0;
void fun0(ll *tmp, int st, int en, ll sum) {
    if (st == en) {
        tmp[sum+2500000]++;
        return;
    }
    fun0(tmp, st + 1, en, sum + v[st]);
    fun0(tmp, st + 1, en, sum);
}
void fun1(vector<ll> &tmp, int st, int en, ll sum)
{
    if (st == en)
    {
        tmp.push_back(sum);
        return;
    }
    fun1(tmp, st + 1, en, sum + v[st]);
    fun1(tmp, st + 1, en, sum);
}

int main() {
    fastio;

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        v.push_back(t);
    }

    fun0(a1, 0, (n + 1) / 2, 0);
    fun1(v2, (n + 1) / 2, n, 0);

    for (auto i : v2) {
        if (s - i <= 2500000 && 0 <= 2500000 + s - i)
            ans += a1[2500000 + s - i];
    }

    if (s==0)
        ans--;

    cout << ans;

    return 0;
}