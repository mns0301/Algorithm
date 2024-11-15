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
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int n, m, cnt, height = 1;
vvi v(102, vi(72, 0)), visited(102, vi(72, 0));

void dfs(int k, pii pos) {
    // int pre = k;
    int y = pos.first;
    int x = pos.second;

    // int now = v[y][x];
    //visited[y][x] = 1;

    for (int i = 0; i < 8; i++) {
        if (visited[y+dy[i]][x+dx[i]] == 0 && v[y + dy[i]][x + dx[i]] == k) {
            visited[y + dy[i]][x + dx[i]] = 1;
            dfs(k, { y + dy[i], x + dx[i] });
        }
        
        if (v[y + dy[i]][x+dx[i]] > k) {
            height = 0;
        }
    }

}

int main() {
	fastio;

    cin >> n >> m;
    // v.resize(n + 2);
    // visited.resize(n + 2);
    // f(i, n+2) {
    //     v[i].resize(m + 2);
    //     visited[i].resize(m + 2);
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int now = v[i][j];
            if (!visited[i][j] && now) {
                height = 1;
                // if (now <= v[i][j + 1] || now <= v[i + 1][j + 1] || now <= v[i + 1][j] || now <= v[i + 1][j - 1])
                //     continue;
                visited[i][j] = 1;
                dfs(now, {i, j});
                if (height) cnt++;
            }
		}
    }

    cout << cnt;

    return 0;
}