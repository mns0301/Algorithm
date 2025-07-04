#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n = 1, m;
    vector<int> v(2, 0);
    cin >> v[1] >> m;
    for (int i = 0; i < m; i++) 
        n <<= 1;
    n--;
    for (int i = 1; i <= n; i++) {
        v.push_back(v[i] / 2);
        v.push_back((v[i] + 1) / 2);
    }
    long long s = 0;
    for (int i = 1; i <= n * 2 + 1; i++) 
        s += v[i];
    cout << s;
    return 0;
}