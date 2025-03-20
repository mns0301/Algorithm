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

// map<ll, int> m;
vector<ll> v1;
map<ll, int> m1;
vector<ll> v;
int n;
ll s;
ll ans = 0;

void fun(int depth, ll sum) {
    if (depth == (n + 1)/2) {
        v1.push_back(sum);
        // m[sum]++;
        return;
    }
    fun(depth + 1, sum + v[depth]);
    fun(depth + 1, sum);
}

void fun1(int depth, ll sum) {
    if (depth == n) {
        m1[sum]++;
        ans += upper_bound(v1.begin(), v1.end(), s - sum) - lower_bound(v1.begin(), v1.end(), s - sum);
        // if (m.find(s-sum) != m.end())
        //     ans += m[s - sum];
        return;
    }
    
    fun1(depth + 1, sum + v[depth]);
    fun1(depth + 1, sum);
}

int main() {
    fastio;

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        v.push_back(t);
    }

    fun(0, 0);
    v1.pop_back();
    sort(v1.begin(), v1.end());
    // m[0]--;

    fun1((n + 1) / 2, 0);
    m1[0]--;

    if (m1.find(s) != m1.end())
        ans += m1[s];

    cout << ans;

    return 0;
}