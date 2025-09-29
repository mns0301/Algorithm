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
    vector<vector<int>> dp(2, vector<int>(n, 0));

    if (n % 4 == 2 || n % 4 == 3)
        cout << -1;
    else {
        int l = 0, r = n - 1;
        int t = n;
        while (t >= 4) {
            dp[0][l] = t;
            dp[1][l] = t-1;
            dp[0][l+1] = t-2;
            dp[1][l+1] = t-3;

            dp[0][r] = t-2;
            dp[1][r] = t;
            dp[0][r-1] = t-1;
            dp[1][r-1] = t-3;
            l += 2;
            r -= 2;
            t -= 4;
        }
        if (n%4 == 1) {
            dp[0][n / 2] = 1;
            dp[1][n / 2] = 1;
        }
        for (int i = 0; i < n; i++)
            cout << dp[0][i] << " ";
        cout << "\n";
        for (int i = 0; i < n; i++)
            cout << dp[1][i] << " ";
    }

    return 0;
}