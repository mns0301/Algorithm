#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        cout << n << " " << c << "\n";
        cout << (c - 2) * n + 2 << "\n";
    }
}