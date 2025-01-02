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
#define f1(i, n) for(int i = 1; i <= n; i++)

int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void fun() {
    vpll pos(4);
    f(i, 4) cin >> pos[i].first >> pos[i].second;

    vl dis(6);
    int x = 0;
    for (int i = 0; i < 3; i ++) {
        for (int j = i + 1; j < 4; j++) {
            dis[x++] = (pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second);
        }
    }
    sort(dis.begin(), dis.end());

    if ((dis[4] == dis[5]) && (dis[0] == dis[1]) && (dis[1]==dis[2]) && (dis[2] == dis[3])) cout << 1;
    else cout << 0;

    cout << "\n";
}

int main() {
    fastio;

    int t;
    cin >> t;
    w(t) fun();

    return 0;
}