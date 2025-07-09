#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

void fun() {
    int w, n;
    cin >> w >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i].first >> v[i].second;

    int dist = 0, weight = 0, pre = 0;
    for (auto [xi, wi] : v) {
        dist += xi - pre;
        if (weight + wi <= w) {
            weight += wi;
            if (weight == w && xi != v[n-1].first) {
				weight = 0;
                dist += xi << 1;
            }
        } else if (weight + wi > w) {
			weight = wi;
            dist += xi << 1;
        }
		pre = xi;
    }
    cout << dist + v[n-1].first << "\n";
}

int main() {
	fastio;

    int t;
    cin >> t;
	while (t--)
        fun();

    return 0;
}