#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int a, b, n;
        cin >> a >> b;
        n = a + b;
        cout << n * (n-1) / 2 * n << "\n";
    }
}