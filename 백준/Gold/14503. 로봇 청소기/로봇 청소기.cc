#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

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