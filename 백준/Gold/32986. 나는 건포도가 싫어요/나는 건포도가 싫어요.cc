#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int x, y, z;
    cin >> x >> y >> z;

    if (x == 3 && y == 3 && z == 3) {
        cout << 0;
        return 0;
    }
    int ans = (min(x, min(y, z)) - 1) / 2;
    cout << ans;

    return 0;
}