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

void dfs(vi graph[], int v, int n) {
    int cnt = 1;
    vi visited(n + 1, 0);
    stack<int> st;
    st.push(v);

    while (!st.empty()) {
        int now = st.top();
        st.pop();

        if (visited[now] == 1) continue;
        else {
            cout << now << " ";
            visited[now] = 1;
        }

        for (int i = graph[now].size() - 1; i >= 0; i--) {
            int nxt = graph[now][i];
            if (visited[nxt] == 0)
                st.push(nxt);
        }
    }

    cout << "\n";
}

void bfs(vi graph[], int v, int n)
{
    int cnt = 1;
    vi visited(n + 1, 0);
    queue<int> qu;
    qu.push(v);

    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();

        if (visited[now] == 1)
            continue;
        else {
            cout << now << " ";
            visited[now] = 1;
        }

        for (int i = 0; i < graph[now].size(); i++)
        {
            int nxt = graph[now][i];
            if (visited[nxt] == 0)
                qu.push(nxt);
        }
    }

    cout << "\n";
}

int main() {
    fastio;

    int n, m, v;
    cin >> n >> m >> v;
    int a[10];

    vi graph[n + 1];

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) 
        sort(graph[i].begin(), graph[i].end());

    dfs(graph, v, n);
    bfs(graph, v, n);

    return 0;
}