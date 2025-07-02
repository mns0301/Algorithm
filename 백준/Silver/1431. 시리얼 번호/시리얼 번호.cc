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

int nc(string a) {
    int tmp = 0;
    for (int i = 0; i < a.size(); i++) {
        if ('0' <= a[i] && a[i] <= '9') {
            tmp += a[i] - '0';
        }
    }
    return tmp;
}

bool comp(string a, string b) {
    if (a.size() == b.size())  {
        int aa = nc(a), bb = nc(b);
        if (aa == bb) {
            return a < b;
        }
        return aa < bb;
    }
    return a.size() < b.size();
}

int main() {
    fastio;

    int n;
    cin >> n;
    vector<string> v(n);
    f(i, n) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), comp);

    f(i, n) {
        cout << v[i] << '\n';
    }

    return 0;
}