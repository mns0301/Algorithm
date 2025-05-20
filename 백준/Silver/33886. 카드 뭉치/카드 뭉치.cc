#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long
#define vi vector<int>

int main() {
    fastio;

    int n, cnt = 0, nxt = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = n - 1; i >= 0; i--) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        cnt++;
        nxt = i;
        for (int j = i + 1; j < n; j++) {
            if (j - v[j] < i) {
                nxt = j;
            }
        }
        i = nxt;
    }
    cout << cnt;

    return 0;
}