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

    int n, m;
    cin >> n >> m;
    vvi v1(n + 1, vi(n + 1, 0));
    vvi v2(n + 1, vi(n + 1, 0));
    f1(i, n) {
        f1(j, n) cin >> v1[i][j];
    }
    f1(i, n) {
        f1(j, n) cin >> v2[i][j];
    }

    vi x(n + 1, 0);
	f1(i, n) {
		f1(j, n) {
            x[i] = max(x[i], abs(v1[j][i] - v2[j][i]));
        }
    }
    int sum = 0;
    w(m) {
        int tmp = 0;
        cin >> tmp;
        sum += x[tmp];
    }

    cout << sum;

    return 0;
}