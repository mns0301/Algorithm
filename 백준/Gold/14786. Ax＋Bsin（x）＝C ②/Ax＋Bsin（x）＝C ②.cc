#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long double a, b, c;
    cin >> a >> b >> c;
    long double l = (c - b) / a;
    long double r = (c + b) / a;
    long double ans = (l + r) / 2.0;
    long double temp = a * ans + b * sin(ans);

    while (abs(temp - c) > 1e-9) {
        if (temp < c) l = ans;
        else r = ans;
        ans = (l + r) / 2.0;
        temp = a * ans + b * sin(ans);
    }

    cout << fixed << setprecision(9) << ans;

    return 0;
}
