#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int distance(pair<int, int> a, pair<int, int> b) {
    return (a.second - b.second) * (a.second - b.second) + (a.first - b.first) * (a.first - b.first);
}

int main() {
    fastio;

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;   
    }
    sort(v.begin(), v.end());
    s.insert({ v[0].second, v[0].first });
    s.insert({ v[1].second, v[1].first });
    int min_dis = distance(v[0], v[1]);

    int j = 0;
    for (int i = 2; i < n; i++) {
        for (j; j < i; j++) {
            if ((v[i].first - v[j].first) * (v[i].first - v[j].first) <= min_dis)
                break;

            s.erase({ v[j].second, v[j].first });
        }

        auto start = s.lower_bound({ v[i].second - int(sqrt(min_dis)), -10001 });
        auto end = s.upper_bound({ v[i].second + int(sqrt(min_dis)), 10001 });
        for (auto it = start; it != end; it++) {
            min_dis = min(min_dis, distance(v[i], { it->second, it->first }));
        }
        s.insert({ v[i].second, v[i].first });
    }

    cout << min_dis;
    return 0;
}
