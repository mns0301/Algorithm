#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define vi vector<int>
#define vvi vector<vi>
#define ai3 array<int, 3>
#define qai3 queue<ai3>
#define w(t) while(t)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define defvari2(a, b) int a, b;
#define defvari3(a, b, c) int a, b, c;
#define inputi2(n, m) cin >> n >> m;
#define inputi1(n) cin >> n;
#define outputi1(n) cout << n;
#define pushai3(a, b, c) push({ a, b, c });
#define matchvii2(a, b, c, d) a = c, b = d;
#define matchvpi3(a, b, c, d) a = d[0], b = d[1], c = d[2];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

defvari3(n, m, a)

int main() {
    fastio;

    inputi2(m, n)
    vvi v(n + 2, vi(m + 2, -1));
    qai3 q;

    f1(i, n) {
        f1(j, m)  {
            inputi1(v[i][j]);
            if (v[i][j] == 1)
                q.pushai3(i, j, 0);
        }
    }

    w(q.size()) {
        defvari3(y, x, d);
        matchvpi3(y, x, d, q.front());
        q.pop();

        a = d++;
        for (int i = 0; i < 4; i++) {
            defvari2(ny, nx);
            matchvii2(ny, nx, y + dy[i], x + dx[i]);
            if (!v[ny][nx]) {
                v[ny][nx] = 1;
                q.pushai3(ny, nx, d);
            }
        }
    }

    f1(i, n) {
        f1(j, m) {
            if (!v[i][j])
                a = -1;
        }
    }

    outputi1(a);

    return 0;
}