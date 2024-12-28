#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int s, m;
    cin >> s >> m;
    int a = (s + m) / 2;
    int b = (s - m) / 2;
    if (a < 0 || b < 0 || (s + m) % 2 || (s - m) % 2)
        cout << -1;
    else
        cout << max(a, b) << " " << min(a, b);
}
// (s-m)/2= b+b
// (s+m)/2 = a