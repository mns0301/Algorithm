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

    int n, b, h, w;
    int mini = 1e9;
    cin >> n >> b >> h >> w;
    for (int i = 0; i < h; i++) {
        int cost;
        cin >> cost;
        for (int j = 0; j < w; j++) {
            int tmp;
            cin >> tmp;
            if (tmp >= n && cost*n <= b) {
                mini = min(cost * n, mini);
            }
        }
    }

    if (mini != 1e9)
        cout << mini;
    else
        cout << "stay home";

        return 0;
}