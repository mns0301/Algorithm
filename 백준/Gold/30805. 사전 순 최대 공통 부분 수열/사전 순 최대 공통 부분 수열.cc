#include <iostream>
#include <vector>
#include <algorithm>
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

    int n, m;
    vector<int> v[101], w[101];
    cin >> n;
    f(i, n) {
        int t;
        cin >> t;
        v[t].push_back(i);
    }
    cin >> m;
    f(i, m) {
        int t;
        cin >> t;
        w[t].push_back(i);
    }
    vi ans;
    int iv = -1, iw = -1;
    for (int i = 100; i >= 0; i--) {
        if (v[i].empty() || w[i].empty()) continue;

    xxxx:;
        int t1 = -1, t2 = -1;
        foreach (x, v[i]) {
            if (iv < x) {
                t1 = x;
                break;
            }
        }
        foreach(x, w[i]) {
            if (iw < x) {
                t2 = x;
                break;
            }
        }

        if (t1 == -1 || t2 == -1) continue;
        else {
            iv = t1;
            iw = t2;
            // cout << iv << " " << iw << "\n";
            ans.push_back(i);
            goto xxxx;
        }
    }
    cout << ans.size() << "\n";
    foreach(x, ans)
        cout << x << ' ';

    return 0;
}