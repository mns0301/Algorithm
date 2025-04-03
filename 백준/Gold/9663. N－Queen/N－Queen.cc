#include <iostream>
using namespace std;

int ans, n, xx[15], yy[15], c1[30], c2[30];

void fun(int x) {
    if (x == n) {
        ans++;
        return;
    }
    if (xx[x])
        return;
    xx[x] = 1;
    for (int i = 0; i < n; i++) {
        if (yy[i] || c1[x + i] || c2[n - x + i])
            continue;
        yy[i] = c1[x + i] = c2[n - x + i] = 1;
        fun(x + 1);
        c2[n - x + i] = c1[x + i] = yy[i] = 0;
    }
    xx[x] = 0;
}

int main() {
    cin >> n;
    fun(0);
    cout << ans;
    return 0;
}