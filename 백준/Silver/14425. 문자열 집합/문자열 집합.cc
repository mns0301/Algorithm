#include <iostream>
#include <set>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

int main() {
    fastio;
    int n, m, i, cnt = 0;
    cin >> n >> m;
    set<string> s;
    for (i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (s.find(str) != s.end())
            cnt++;
    }
    cout << cnt;
}