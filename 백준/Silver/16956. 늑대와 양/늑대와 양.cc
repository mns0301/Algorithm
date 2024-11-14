#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)

int main() {
    fastio;

    int r, c;
    cin >> r >> c;
    vector<vector<char>> v(r+2, vector<char>(c+2, '.'));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (v[i][j] == 'S') {
                if (v[i - 1][j] == 'W' || v[i + 1][j] == 'W' || v[i][j - 1] == 'W' || v[i][j + 1] == 'W') {
                    cout << 0;
                    return 0;
                }
                if (v[i-1][j] != 'S')
                    v[i-1][j] = 'D';
                if (v[i+1][j] != 'S')
                    v[i+1][j] = 'D';
                if (v[i][j-1] != 'S')
                    v[i][j-1] = 'D';
                if (v[i][j+1] != 'S')
                    v[i][j+1] = 'D';
            }
        }
    }

    cout << 1 << "\n";
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++)
        {
            cout << v[i][j];
        }
        cout << "\n";
    }

        return 0;
}