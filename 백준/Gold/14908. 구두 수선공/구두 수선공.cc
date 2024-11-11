#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <map>
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

    int n;
    cin >> n;
    vpii v(n + 1);
    vi cost(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
        cost[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int a1 = v[i].first * v[j].second;
            int a2 = v[j].first * v[i].second;
            if (a1 > a2) {
                swap(v[i], v[j]);
                swap(cost[i], cost[j]);
            }
            else if (a1 == a2) {
                if (cost[i] > cost[j])
                    swap(cost[i], cost[j]);
            }
        }

        // for (int j = 1; j <= n; j++)
        //     cout << cost[j] << " ";
        // cout << "\n";
    }
    for (int j = 1; j <= n; j++)
        cout << cost[j] << " ";

    return 0;
}