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
#define f1(i, n) for(int i = 1; i <= n; i++)

int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    vi v(n, 0);
    f(i, n) cin >> v[i];

    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += v[j];
            if (sum == k)
                cnt++;
            if (sum > k) break;
        }
    }

    cout << cnt;
    return 0;
}