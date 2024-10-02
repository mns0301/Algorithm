#include <iostream>
using namespace std;

int main() {

    int n, cnt = 0, a = 64;
    cin >> n;

    while (n) {
        if (n >= a) {
            n -= a;
            cnt++;
        }
        a /= 2;
    }

    cout << cnt;
    
    return 0;
}
