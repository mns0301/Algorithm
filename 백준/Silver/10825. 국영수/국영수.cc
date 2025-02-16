#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n;
    cin >> n;
    vector<tuple<int ,int, int, string>> v;
    for (int i = 0; i < n; i++) {
        string name;
        int kor, eng, mat;
        cin >> name >> kor >> eng >> mat;
        v.push_back({ -kor, eng, -mat, name });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        cout << get<3>(v[i]) << "\n";

        return 0;
}