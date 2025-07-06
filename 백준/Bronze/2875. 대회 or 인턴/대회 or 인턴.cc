#include <iostream>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    cout << min(min(n / 2, m), (n + m - k) / 3);

    return 0;
}