#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
//#define int long long
#define ll long long
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

int main() {
	fastio;

    vvi graph(52);
    vvi capacity(52, vi(52, 0));
    vvi flow(52, vi(52, 0));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
		char a, b;
        int c;
        cin >> a >> b >> c;
        a = (a >= 'a' ? a - 'a' + 26 : a - 'A');
        b = (b >= 'a' ? b - 'a' + 26 : b - 'A');
        graph[a].push_back(b);
        graph[b].push_back(a);
        capacity[a][b] += c;
        capacity[b][a] += c;
    }

    int ans = 0;

	while(true) {
        vi parent(52, -1);
        queue<int> q;
        q.push(0);

        while (q.size() && parent['Z' - 'A'] == -1) {
            int cur = q.front();
            q.pop();

            foreach(nxt, graph[cur]) {
				if (capacity[cur][nxt] - flow[cur][nxt] <= 0 || parent[nxt] != -1) continue;

                parent[nxt] = cur;
                q.push(nxt);

				if (nxt == 'Z' - 'A')
                    break;
            }
        }

        if (parent['Z' - 'A'] == -1)
            break;

        int v = 1e9;
        for (int cur = 'Z' - 'A'; cur != 0; cur = parent[cur])
            v = min(capacity[parent[cur]][cur] - flow[parent[cur]][cur], v);

        for (int cur = 'Z' - 'A'; cur != 0; cur = parent[cur]) {
			flow[parent[cur]][cur] += v;
            flow[cur][parent[cur]] -= v;
        }
        ans += v;
    }

    cout << ans;

    return 0;
}