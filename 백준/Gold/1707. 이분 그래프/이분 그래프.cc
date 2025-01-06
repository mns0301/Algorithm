#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int change_color(int color) {
    if (color==1)
        return 2;
    else
        return 1;
}

int bfs(vector<vector<int>>& graph, int v, int e) {
    vector<int> visited(v + 1, 0);
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    visited[1] = 1;

    int flag = 1;

    y :
    while (q.size()) {
        int now = q.front().first;
        int color = q.front().second;
        int nxt_color = change_color(color);
        q.pop();

        for (int nxt : graph[now]) {
            if (visited[nxt] == color) {
                flag = 0;
                goto x;
            }
            else if (visited[nxt] == nxt_color)
                continue;
            else {
                visited[nxt] = nxt_color;
                q.push({ nxt, nxt_color });
            }
        }
    }

    x :

    if (flag == 0)
        return 0;
    
    int i = 1;
    for (i; i <= v; i++)
    {
        if (visited[i] == 0)
        {
            q.push({ i, 1 });
            visited[i] = 1;
            goto y;
        }
    }

    return 1;
}

void fun() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v + 1);

    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << (bfs(graph, v, e) ? "YES\n" : "NO\n");
}

int main(void) {
    int k;
    cin >> k;
    while (k--) {
        fun();
    }
    
}

// 모든 그래프가 연결되있지 않을 수 있음