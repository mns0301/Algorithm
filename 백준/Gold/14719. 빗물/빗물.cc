#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    int h, w;
    cin >> h >> w;
    vector<int> v(w, 0);
    int start;
    int past;
    int ans = 0;
    for (int i = 0; i < w; i++)
        cin >> v[i];

    for (int i = 1; i < w - 1; i++) {
        int base = v[i];
        int le = v[i], ri = v[i];
        for (int l = 0; l < i; l++) {
            le = max(v[l], le);
        }
        for (int r = i + 1; r < w; r++) {
            ri = max(v[r], ri);
        }
        ans += min(le, ri) - base;
    }
    cout << ans;
    
    return 0;
}