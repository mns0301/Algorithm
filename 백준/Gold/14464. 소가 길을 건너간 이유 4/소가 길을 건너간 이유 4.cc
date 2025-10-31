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

int dy8[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx8[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy4[4] = { -1, 0, 1, 0 };
int dx4[4] = { 0, 1, 0, -1 };

int main() {
	fastio;

    int c, n;
    cin >> c >> n;
    vi chicken(c);
    f(i, c) cin >> chicken[i];
    sort(chicken.begin(), chicken.end());
    vpii cow(n);
    f(i, n) cin >> cow[i].first >> cow[i].second;
    sort(cow.begin(), cow.end());
    int ans = 0;
    int cur_chi = 0;
    int cur_cow = 0;
    priority_queue<int> pq; // -second

	while (cur_chi < c)
	{
		if (cur_cow < n && cow[cur_cow].first <= chicken[cur_chi])
		{
            // cout << "push: " << cur_cow << "\n";
            pq.push(-cow[cur_cow].second);
            cur_cow++;
			continue;
        }
		else {
			if (pq.size()) {
                int w = -pq.top();
                pq.pop();
				if (chicken[cur_chi] <= w) {
                    // cout << chicken[cur_chi] << ", " << w << "s\n";
                    cur_chi++;
                    ans++;
					continue;
                }
            }
			else if (pq.empty())
                cur_chi++;
        }
    }
    cout << ans;

    return 0;
}