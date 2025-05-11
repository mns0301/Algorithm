#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m - 1; i++)
        v.push_back({ i, m - 1 });
    for (int i = m - 1; i < n - 1; i++)
        v.push_back({ i, i + 1 });

    for (int i = 0; i < n - 1; i++) 
        cout << v[i].first << " " << v[i].second << "\n";
}