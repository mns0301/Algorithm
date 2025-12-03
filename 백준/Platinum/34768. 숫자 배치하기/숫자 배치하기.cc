#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
//#define int long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define loop(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define foreach(i, v) for(auto i : v)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

int dy8[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dx8[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
int dy4[4] = { 0, 0, -1, 1 };
int dx4[4] = { -1, 1, 0, 0 };

int main() {
    fastio;

    int n, t;
    cin >> n;
    t = n * n / 2;
    vvi v(n, vi(n, 0));
    for (int i = 0; i < n; i+=2) {
        for (int j = 0; j < n; j+=2) {
            v[i][j] = t;
            v[i + 1][j] = t - 1;
            v[i][j + 1] = t - 1;
            v[i + 1][j + 1] = t - 2;
            t -= 2;
        }
    }
    v[n - 1][n - 1] = n * n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }

        return 0;
}