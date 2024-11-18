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

void fun() {
    priority_queue<ll> small, big;
    vl ans;
    ll m, mid;
    cin >> m;

    for (int i = 0; i < m; i++) {
        ll tmp;
        cin >> tmp;

        if (i==0)
            mid = tmp;
        else if (tmp >= mid) {
            big.push(-tmp);

            if (big.size() == small.size() + 2) {
                small.push(mid);
                mid = -big.top();
                big.pop();
            }
        }
        else if (tmp < mid) {
            small.push(tmp);

            if (small.size() == big.size() + 2) {
                big.push(-mid);
                mid = small.top();
                small.pop();
            }
        }

        if (i%2==0)
            ans.push_back(mid);
    }

    cout << (m + 1) / 2 << "\n";
    f(i, ans.size()) {
        if (i!=0 && i % 10 == 0)
            cout << "\n";
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    fastio;

    int t;
    cin >> t;
    w(t) fun();

    return 0;
}   