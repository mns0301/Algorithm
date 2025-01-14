#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int main()
{
    fastio;

    int n;
    cin >> n;
    vector<pair<int, int>> path(n);
    for (int i = 0; i < n; i++)
        cin >> path[i].first >> path[i].second;
    sort(path.begin(), path.end());

    int sp = path[0].first, ep = path[0].second;
    int mp = ep + ep - sp;

    for (int i = 1; i < n; i++) {
            if (path[i].first <= ep)
                ep = max(ep, path[i].second);
            else if (path[i].first <= mp) {
                sp = path[i].first;
                ep = path[i].second;
            }
            mp = max(mp, ep + ep - sp);
        }
    cout << ep;

    return 0;
}