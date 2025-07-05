#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        cout << "Case #" << i << ": " << max(a,max(max(b,c),max(d,e))) << "\n";
    }

        return 0;
}