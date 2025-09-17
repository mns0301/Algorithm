#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    int n, l = -1, r = -1;
    cin >> n;
    vector<int> an(n + 1, 0);
    vector<int> sn(n + 1, 0);
    vector<char> op(n + 1, 0);
    vector<int> hole(20001, -1);
    hole[10000] = 0;

    for (int i = 1; i <= n; i++)
        cin >> an[i];
    for (int i = 1; i <= n; i++) {
        if (sn[i-1] <= 0) {
            sn[i] = sn[i - 1] + an[i];
            op[i] = '+';
        }
        else if (sn[i-1] > 0) {
            sn[i] = sn[i - 1] - an[i];
            op[i] = '-';
        }

        if (hole[sn[i] + 10000] != -1) {
            l = hole[sn[i] + 10000] + 1;
            r = i;
            // cout << l << " : " << r << "\n";
        }
        hole[sn[i] + 10000] = i;
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << sn[i] << " ";
    // }
    if (l == r) {
        cout << an[1];
        for (int i = 2; i <= n; i++) 
            cout << "*" << an[i];
        return 0;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        if (i < l) {
            cout << an[i] << "*";
        }
        if (i == l) {
            cout << "(" << an[i];
        }
        if (l < i && i < r) {
            if (op[l] == '-')
                cout << (op[i] == '+' ? '-' : '+');
            else
                cout << op[i];
            cout << an[i];
        }
        if (r == i) {
            if (op[l] == '-')
                cout << (op[i] == '+' ? '-' : '+');
            else
                cout << op[i];
            cout << an[i] << ")";
        }
        if (r < i) {
            cout << "*" << an[i];
        }
    }

        return 0;
}