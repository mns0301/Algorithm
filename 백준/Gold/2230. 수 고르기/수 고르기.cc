#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n, m, s = 0, e = 0, x = 2e9;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    while (s <= e) {
        int d = v[e] - v[s];
        if (d >= m) {
            s++;
            x = min(x, d);
        }
        else if (d < m) 
            e++;

        if (e == n)
            break;
    }

    cout << x;

    return 0;
}