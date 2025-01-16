#include <iostream>
using namespace std;

int yy[5] = { 0 };
int xx[5] = { 0 };
int c1, c2;
int cnt = 0;

void chk(int x, int y) {
    yy[y]++;
    if (yy[y] == 5)
        cnt++;
    xx[x]++;
    if (xx[x]==5)
        cnt++;
    if (y == x) {
        c1++;
        if (c1 == 5)
            cnt++;
    }
    if (y == 4-x) {
        c2++;
        if (c2 == 5)
            cnt++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cin >> v[i][j];
    }

    for (int i = 1; i <= 25; i++) {
        int t;
        cin >> t;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                if (v[y][x] == t) {
                    chk(x, y);
                    if (cnt>=3) {
                        cout << i;
                        goto e;
                    }
                    goto s;
                }
            }
        }
        s:;
    }
    
    e:

    return 0;
}