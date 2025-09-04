#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    string s;
    cin >> s;
    int sz = 0;
    int arr[3] = { 0, 0, 0 };

    for (char c : s) {
        int idx = c - 'A';
        arr[idx]++;
        if (arr[0] && arr[1] && arr[2]) {
            arr[0]--;
            arr[1]--;
            arr[2]--;
        }
        sz = max(max(sz, arr[0]), max(arr[1], arr[2]));
    }
    cout << sz;

    return 0;
}