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

    int n;
    cin >> n;
    vector<vpii> graph(n + 1);
    vi iq(n + 1);
    f1(i, n) cin >> iq[i];
    f(i, n-1) {
        int v, w;
        cin >> v >> w;
        graph[v].push_back({ iq[w], w });
    }
    f1(i, n) sort(graph[i].begin(), graph[i].end(), greater());
    f1(i, n) {
        for (int cur = 0; cur < graph[i].size(); cur++) {
            if (cur == 0)
                cout << i << " " << graph[i][cur].second << "\n";
            else
                cout << graph[i][cur - 1].second << " " << graph[i][cur].second << "\n";
        }
    }

    return 0;
}