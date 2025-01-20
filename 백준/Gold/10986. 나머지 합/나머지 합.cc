#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n, k, t;
    long long cnt = 0;
    cin >> n >> k;
    vector<long long> v(n + 1, 0);
    vector<long long> x(k, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t;
        v[i] = v[i - 1] + t;
    }
    for (int i = 0; i <= n; i++)
        x[v[i] % k]++;
    for (int i = 0; i < k; i++)
        cnt += x[i] * (x[i] - 1) / 2;

    cout << cnt;

    return 0;
}