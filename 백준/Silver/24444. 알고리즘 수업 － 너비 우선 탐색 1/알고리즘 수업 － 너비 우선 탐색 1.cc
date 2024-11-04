#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define str string
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

vi visited;

void bfs(vvi& graph, int r) {
    queue<int> q;
    q.push(r);
    int cnt = 1;

    while (q.size()) {
        int now = q.front();
        q.pop();

        visited[now] = cnt;
        cnt++;

        f(i, graph[now].size()) {
            if (visited[graph[now][i]] == 0) {
                q.push(graph[now][i]);
                visited[graph[now][i]] = 1;
            }
        }
    }
}

int main() {
    fastio;

    int n, m, r;
    cin >> n >> m >> r;
    vvi graph(n + 1);
    visited.resize(n + 1);

    f(i, m) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());
    
    bfs(graph, r);

    for (int i = 1; i <= n; i++) 
        cout << visited[i] << "\n";

    return 0;
}