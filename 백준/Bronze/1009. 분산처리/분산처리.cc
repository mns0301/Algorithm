#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void fun() {
    long long a, b;
    cin >> a >> b;
    long long x = 1, i = 0;
    for (i = 0; i < b; i++) {
        x = (x * a) % 10;
    }
    cout << (x % 10 ? x % 10 : 10) << "\n";
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--)
        fun();

    return 0;
}