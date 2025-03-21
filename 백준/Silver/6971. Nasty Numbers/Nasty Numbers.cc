#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        set<int> p, m;
        int t;
        cin >> t;
        int ans = 0;
        for (int i = 1; i * i <= t; i++) {
            if (t%i==0) {
                int j = t / i;
                if (p.find(abs(i - j)) != p.end() ||m.find(i + j) != m.end()) {
                    ans = 1;
                    break;
                }
                m.insert(abs(i - j));
                p.insert(i + j);
            }
        }
        if (ans == 1)
            cout << t << " is nasty\n";
        else
            cout << t << " is not nasty\n";
    }

        return 0;
}