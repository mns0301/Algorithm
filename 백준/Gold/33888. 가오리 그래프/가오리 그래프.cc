#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
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

int n;
vvi v(51);
vi deg(51);
vi gaori(6); // head left center right under tail
vi visited(51, 0);
vi body;
set<int> s;

int main() {
    fastio;

    int tail = -1;
    cin >> n;
    for (int i = 0; i < n + 3; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] >= 3)
            s.insert(i);

        if (deg[i] == 1) {
            s.insert(i);
            gaori[5] = i;
            tail = i;
        }
    }

    queue<int> q;
    q.push(tail);
    visited[tail] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur != tail && s.find(cur) != s.end()) 
            gaori[4] = cur;
        else {
            for (int nxt : v[cur]) {
                if (visited[nxt] == 0) {
                    q.push(nxt);
                    visited[nxt] = 1;
                }
            }
        }
    }


    q.push(gaori[4]);
    visited[gaori[4]] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur != gaori[4] && s.find(cur) != s.end()) {
            body.push_back(cur);
            visited[cur] = 1;
        }
        else {
            for (int nxt : v[cur]) {
                if (visited[nxt] == 0) {
                    q.push(nxt);
                    visited[nxt] = 1;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (deg[body[i]] == 4) {
            gaori[2] = body[i];
            swap(body[i], body[2]);
            gaori[1] = min(body[0], body[1]);
            gaori[3] = max(body[0], body[1]);
            break;
        }
    }

    for (int tmp : s) {
        int flag = 0;
        for (int i = 1; i < 6; i++) {
            if (gaori[i] == tmp) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            gaori[0] = tmp;
            break;
        }
    }

    for (int x : gaori) {
        cout << x << " ";
    }

        return 0;
}