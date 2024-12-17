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

int main() {
    fastio;

    int pa[101][101] = { 0 };

    int n, m;
    cin >> n >> m;

    w(n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                pa[i][j]++;
            }
        }
    }

    int cnt = 0;
    f1(i,100) {
        f1(j,100) {
            if (pa[i][j] > m)
                cnt++;
        }
    }
    cout << cnt;

    return 0;
}