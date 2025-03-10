#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<vector<double>> a(6, vector<double>(7));
vector<double> ans(6);
int n;

void pivoting(int i) {
    int j = i;
    for (j; j < n; j++) {
        if (a[j][i] != 0) 
            break;
    }
    swap(a[i], a[j]);
} 

int main() {
    fastio;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];
    }

    for (int idx = 0; idx < n - 1; idx++) {
        if (a[idx][idx] == 0)
            pivoting(idx);

        for (int t = idx + 1; t < n; t++) {
            double mul = a[t][idx] / a[idx][idx];
            for (int idx2 = idx; idx2 <= n; idx2++) {
                a[t][idx2] -= a[idx][idx2] * mul;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[i][j] * ans[j];
        }
        ans[i] = a[i][n] / a[i][i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

        return 0;
}