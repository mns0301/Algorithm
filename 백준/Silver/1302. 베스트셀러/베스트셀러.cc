#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> m;
vector<pair<int, string>> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        m[str]++;
    }

    for (auto [i, j] : m) {
        v.push_back({ -j, i });
    }
    sort(v.begin(), v.end());
    cout << v[0].second;

    return 0;
}