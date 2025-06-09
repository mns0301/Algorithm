#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100001] = {0};
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr[t]++;
    }
    for (int i = 1; i <= 100000; i++) {
        if (arr[i]*2 > n + 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}