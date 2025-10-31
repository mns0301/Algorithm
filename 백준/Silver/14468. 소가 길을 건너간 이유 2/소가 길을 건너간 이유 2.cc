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

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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
#define f1(i, n) for(int i = 1; i <= n; i++)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int dy8[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx8[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy4[4] = { -1, 0, 1, 0 };
int dx4[4] = { 0, 1, 0, -1 };

int main() {
	fastio;

    string a;
    cin >> a;
    vector<int> v(52);
    for (int i = 0; i < 52; i++) {
        int x = (int)(a[i] - 'A');
        v[i] = x;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        vector<bool> bit(26, false);
        bool start = false;
        int tmp = -1;
        for (int x = 0; x < 52; x++) {
            if (start == false && v[x] == i)
                start = true;
            else if (start == true && v[x] == i)
                start = false;
            
            if (start) {
                bit[v[x]] = !bit[v[x]];
            }
        }
        for (int x = 0; x < 26; x++) {
            if (bit[x])
                tmp++;
        }
        ans += tmp;
    }
    cout << ans/2;

    return 0;
}