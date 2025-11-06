#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
//#define int long long
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

int main() {
	fastio;

    int n, t;
    cin >> n >> t;
	vvi grid(n + 2, vi(n + 2, -1));
	f1(r, n) {
        f1(c, n) cin >> grid[r][c];
    }
    priority_queue<array<int, 4>> pq; // weight, last_eat, row, col
    vector<vvi> visited(n + 2, vvi(n + 2, vi(3, 1e9)));
    visited[1][1][0] = 0;
    pq.push({ 0, 0, 1, 1 });

	while(pq.size()) {
        auto [w, stk, row, col] = pq.top();
        w = -w;
        pq.pop();

		if (w > visited[row][col][stk]) continue;

        f(i, 4) {
            int nxt_row = row + dy4[i];
            int nxt_col = col + dx4[i];
            int nxt_w = w + t;
            int nxt_stk = stk + 1;
            if (grid[nxt_row][nxt_col] == -1) continue;
            
			if (nxt_stk == 3) {
                nxt_w += grid[nxt_row][nxt_col];
                nxt_stk = 0;
            }

            if (nxt_w < visited[nxt_row][nxt_col][nxt_stk]) {
                visited[nxt_row][nxt_col][nxt_stk] = nxt_w;
                pq.push({ -nxt_w, nxt_stk, nxt_row, nxt_col });
            }
        }
    }

    cout << min(visited[n][n][0], min(visited[n][n][1], visited[n][n][2]));

    return 0;
}