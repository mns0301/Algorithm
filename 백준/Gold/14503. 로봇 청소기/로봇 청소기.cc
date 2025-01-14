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

int rotate_direction(int dir) {
    if (dir == 0)
        return 3;
    else
        return dir - 1;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 1));
    int px, py, dir;
    cin >> py >> px >> dir;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    while (1) {
        if (v[py][px] == 0) {
            cnt++;
            v[py][px] = -1;
        }

        if (v[py + 1][px] == 0 || v[py - 1][px] == 0 || v[py][px + 1] == 0 || v[py][px - 1] == 0) {
            d:
            dir = rotate_direction(dir);

            switch (dir)
            {
            case 0:
                if (v[py - 1][px] == 0)
                    py -= 1;
                else
                    goto d;
                break;
            case 1:
                if (v[py][px + 1] == 0)
                    px += 1;
                else
                    goto d;
                break;
            case 2:
                if (v[py + 1][px] == 0)
                    py += 1;
                else
                    goto d;
                break;
            case 3:
                if (v[py][px - 1] == 0)
                    px -= 1;
                else
                    goto d;
                break;
            }
        }
        else {
            int flag = 1;
            
            switch (dir)
            {
            case 0:
                if (v[py + 1][px] != 1) {
                    py += 1;
                    flag = 0;
                }
                break;
            case 1:
                if (v[py][px - 1] != 1) {
                    px -= 1;
                    flag = 0;
                }
                break;
            case 2:
                if (v[py - 1][px] != 1) {
                    py -= 1;
                    flag = 0;
                }
                break;
            case 3:
                if (v[py][px + 1] != 1) {
                    px += 1;
                    flag = 0;
                }
                break;
            }

            if (flag)
                break;
        }
    }

    cout << cnt;
    return 0;
}