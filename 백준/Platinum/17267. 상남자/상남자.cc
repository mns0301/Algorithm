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

int n, m, l, r;
int px, py;
vvi v(1002, vi(1002, -1));

int bfs() {
    int cnt = 1;
    deque<array<int, 4>> q;
    vvi visited(1001, vi(1001, 0));
    q.push_back({ py, px, l, r });
    visited[py][px] = 1;

    while (q.size()) {
        py = q.front()[0];
        px = q.front()[1];
        int left = q.front()[2];
        int right = q.front()[3];
        q.pop_front();

        if (v[py][px] == 1) continue;

        if (py < n && visited[py + 1][px] == 0){
            if (v[py + 1][px] != 1) {
                visited[py + 1][px] = 1;
                q.push_front({ py + 1, px, left, right });
                cnt++;
            }
        }

        if (py > 1 && visited[py - 1][px] == 0) {
            if (v[py - 1][px] != 1) {
                visited[py - 1][px] = 1;
                q.push_front({ py - 1, px, left, right });
                cnt++;
            }
        }

        if (left > 0 && px > 1 && visited[py][px - 1] == 0) {
            if (v[py][px - 1] != 1) {
                visited[py][px - 1] = 1;
                q.push_back({ py, px - 1, left - 1, right });
                cnt++;
            }
        }

        if (right > 0 && px < m && visited[py][px + 1] == 0) {
            if (v[py][px + 1] != 1) {
                visited[py][px + 1] = 1;
                q.push_back({ py, px + 1, left, right - 1 });
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    fastio;

    cin >> n >> m >> l >> r;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            v[i][j] = str[j - 1] - '0';
            if (v[i][j] == 2) {
                py = i;
                px = j;
            }
        }
    }

    cout << bfs();

    return 0;
}