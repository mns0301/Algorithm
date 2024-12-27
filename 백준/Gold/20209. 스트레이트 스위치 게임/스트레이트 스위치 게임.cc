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

int n, k, cnt = 0;
array<int, 10> sw;
vvi bu(10);

int main() {
    fastio;

    cin >> n >> k;
    f1(i, n) cin >> sw[i];
    f1(i, k) {
        int tmp;
        cin >> tmp;
        bu[i].resize(tmp);
        f(j, tmp) cin >> bu[i][j];
    }

    set<array<int, 10>> s;

    queue<pair<int, array<int, 10>>> q;
    q.push({0,sw});
    s.insert(sw);

    while (q.size()) {
        array<int, 10> now = q.front().second;
        cnt = q.front().first;
        q.pop();

        int is_end = 1;
        for (int i = 1; i < n; i++) {
            if (now[i] != now[i+1]) {
                is_end = 0;
                break;
            }
        }

        if (is_end) {
            break;
        }

        f1(i, k) {
            array<int, 10> nxt(now);
            f(j, bu[i].size()) {
                nxt[bu[i][j]] = (now[bu[i][j]] + i) % 5;
            }
            if (s.find(nxt) == s.end()) {
                s.insert(nxt);
                q.push({cnt + 1, nxt});
            }
        }
        cnt = -1;
    }

    cout << cnt;
    return 0;
}