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

    int n, cur_time = 0, cnt = 0, cur_i = 0;
    cin >> n;
    vpii v(n);
    f(i, n) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [](pii a, pii b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    while (cur_i != n) {
        if (v[cur_i].first >= cur_time) {
            cur_time = v[cur_i].second;
            cnt++;
        }
        cur_i++;
    }


    cout << cnt;

    return 0;
}