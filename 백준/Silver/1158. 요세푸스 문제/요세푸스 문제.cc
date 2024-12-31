#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
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

int main()
{
    fastio;

    deque<int> d;

    int n, k;
    cin >> n >> k;

    f(i, n) d.push_back(i + 1);
    vi ans;

    while (d.size()) {
        for (int i = 0; i < k; i++) {
            d.push_back(d.front());
            d.pop_front();
        }

        ans.push_back(d.back());
        d.pop_back();
    }

    cout << "<";
    f(i, ans.size() - 1) { cout << ans[i] << ", "; }
    cout << ans[ans.size() - 1];
    cout << ">";

    return 0;
}