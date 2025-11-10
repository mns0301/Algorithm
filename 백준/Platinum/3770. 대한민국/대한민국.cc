#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define int long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define loop(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define foreach(i, v) for(auto i : v)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

int dy8[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dx8[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
int dy4[4] = { 0, 0, -1, 1 };
int dx4[4] = { -1, 1, 0, 0 };

void fun(int test) {
    int n, m, k;
    cin >> n >> m >> k;

    vvi grid(n + 1, vi(m + 1, 0));
    vpii path(k);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        path[i] = { a, b };
        grid[a][b] = 1;
    }
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            grid[r][c] = grid[r][c] + grid[r - 1][c] + grid[r][c - 1] - grid[r - 1][c - 1];
        }
    }
    // for (int r = 1; r <= n; r++) {
    //     for (int c = 1; c <= m; c++) {
    //         cout << grid[r][c] << " ";
    //     }
    //     cout << "\n";
    // }
	int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += grid[n][path[i].second - 1] - grid[path[i].first][path[i].second - 1];
    }
    cout << "Test case " << test << ": " << ans << "\n";
}

signed main() {
	fastio;

    int t;
    cin >> t;
    f1(i, t) fun(i);

    return 0;
}