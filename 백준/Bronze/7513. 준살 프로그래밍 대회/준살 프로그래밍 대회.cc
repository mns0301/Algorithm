#include <iostream>
#include <vector>
using namespace std;

void fun(int x) {
    int m, n, k;
    cin >> m;
    vector<string> str(m);
    for (int i = 0; i < m; i++)
        cin >> str[i];

    cin >> n;
    cout << "Scenario #" << x << ":\n";
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int idx;
            cin >> idx;
            cout << str[idx];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        fun(i);

    return 0;
}