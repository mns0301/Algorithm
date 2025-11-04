#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
// #define int long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define loop(t) while (t--)
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define foreach(i, v) for (auto i : v)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

int dy8[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dx8[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
int dy4[4] = { 0, 0, -1, 1 };
int dx4[4] = { -1, 1, 0, 0 };

int main() {
    fastio;

    int n;
    cin >> n;
    vpii v(n);
    f(i, n) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<>> pq;
    int t = 0, i = 0;
	while(true) {
        // t++;+
		while(i < n && v[i].first <= t)
            pq.push(v[i++].second);

		if (pq.size()) {
            t += pq.top();
            pq.pop();
        } else {
			if (i == n)
                break;

            t = v[i].first;
        }
    }
    cout << t;

    return 0;
}