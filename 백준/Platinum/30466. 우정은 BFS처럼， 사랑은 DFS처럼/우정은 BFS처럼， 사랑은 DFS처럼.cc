#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define int long long
//#define ll long long
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

vector<vector<int>> graph(200001);
vector<int> visited(200001, 0);
int cnt = 1;
int ans = 0;

signed main() {
    fastio;

    int n;
    cin >> n;
    vector<int> ver;
    int tmp = n / 2;
    int idx = 1;

    while(tmp--)
        graph[idx].push_back(++idx);    
    for (idx += 1; idx <= n; idx++)
        graph[1].push_back(idx);

    visited[1] = cnt++;
    queue<int> q;
    q.push(1);

    while (q.size())
    {
        int cur = q.front();
        q.pop();
        foreach (nxt, graph[cur]) {
            if (visited[nxt])
                continue;

            ans += abs(cnt - nxt);
            visited[nxt] = cnt++;
            q.push(nxt);
        }
    }
    cout << ans << "\n";


    for (int i = 1; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << i << " " << graph[i][j] << "\n";
        }
    }

        return 0;
}