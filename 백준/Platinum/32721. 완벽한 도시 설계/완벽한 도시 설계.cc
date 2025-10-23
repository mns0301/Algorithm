#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int n, ans, com;
vector<vector<int>> v(1000001);
vector<int> in(1000001, 0);
vector<int> visited(1000001, 0);
vector<vector<int>> comp(1000001);

void dfs(int i) {
	if (visited[i])
        return;
    visited[i] = 1;
    comp[com].push_back(i);
    for (int w : v[i]) {
        dfs(w);
    }
}

int main() {
	fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        v[i].push_back(t);
        v[t].push_back(i);
        in[t]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            com++;
        }
    }
	if (com == 1) {
        for (int i = 1; i <= n; i++)  {
			if (in[i] == 0)
                ans++;
			}
		cout << ans;
		return 0;
    }
    ans = com;
    for (int i = 0; i < com; i++) {
        int flag = 0;
        for (int v : comp[i]) {
            if (in[v] == 0) {
                flag = 1;
                ans++;
            }
        }
        if (flag)
            ans--;
    }
        cout << ans;

    return 0;
}