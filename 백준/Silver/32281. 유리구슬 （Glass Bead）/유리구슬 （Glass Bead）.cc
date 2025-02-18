#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long n, ans, tmp;

int main() {
    fastio;

    string str;
    cin >> n >> str;

    for (long long i = 0; i < n; i++) {
        if (str[i] == '1') {
            tmp++;
            if (i == n-1)
                ans += (long long)(tmp * (tmp + 1) / 2);
        }
        else {
            ans += (long long)(tmp * (tmp + 1) / 2);
            tmp = 0;
        }
    }

    cout << ans;
    return 0;
}