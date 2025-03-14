#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int main()
{
    fastio;

    long long n, k;
    cin >> k >> n;

    cout << (n == 1 ? -1 : ((k * n) % (n - 1) == 0 ? (k * n) / (n - 1) : (k * n) / (n - 1) + 1));

    return 0;
}