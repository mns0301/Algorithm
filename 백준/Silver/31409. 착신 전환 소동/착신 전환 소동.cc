#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> v[i];

    for (int i = 1; i <= n; i++) {
        if (i == v[i]) {
            ans++;
            v[i] = i % n + 1;
        }
    }
    
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";

        return 0;
}