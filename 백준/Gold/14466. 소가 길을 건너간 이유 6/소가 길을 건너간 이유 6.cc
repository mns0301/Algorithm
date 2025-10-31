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
#define int long long
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

vector<vector<int>> grid(300, vector<int>(300, 0));
vector<vector<int>> visited(300, vector<int>(300, 0));

int dfs(int r, int c) {
    visited[r][c] = 1;
    int cnt = (grid[r][c] == 2 ? 1 : 0);
    for (int i = 0; i < 4; i++) {
        int nxt_r = r + dy4[i];
        int nxt_c = c + dx4[i];
		if (grid[nxt_r][nxt_c] == 1 || visited[nxt_r][nxt_c]) continue;
        cnt += dfs(nxt_r, nxt_c);
    }
    return cnt;
}

void print_grid() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}

signed main() {
	fastio;

    int n, k, r;
    cin >> n >> k >> r;

    for (int i = 0; i < 300; i++) {
        grid[0][i] = 1;
        grid[n << 1][i] = 1;
        grid[i][0] = 1;
        grid[i][n << 1] = 1;
    }
    for (int i = 0; i < 300; i+=2) {
        for (int j = 0; j < 300; j+=2)
            grid[i][j] = 1;
    }

        for (int i = 0; i < r; i++) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1 = 2 * r1 - 1;
            c1 = 2 * c1 - 1;
            r2 = 2 * r2 - 1;
            c2 = 2 * c2 - 1;
            grid[(r1 + r2) / 2][(c1 + c2) / 2] = 1;
        }
	
    queue<pair<int, int>> q;
    for (int i = 0; i < k; i++) {
		int r, c;
        cin >> r >> c;
        r = 2 * r - 1;
        c = 2 * c - 1;
        grid[r][c] = 2;
        q.push({ r, c });
    }
	
	// print_grid();
    vector<int> ans;
    while (q.size()) {	
        auto [r, c] = q.front();
        q.pop();

		if (visited[r][c]) continue;
        ans.push_back(dfs(r, c));
    }
    int ss = 0;
    for (int i = 0; i < ans.size();i++) {
        // cout << ans[i] << "\n";
        ss += (k - ans[i]) * ans[i];
    }
    cout << ss / 2;

    return 0;
}