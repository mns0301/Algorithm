#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n + 1, 0);
    v[1] = 1;
    v[2] = 1;
    for(int i = 3; i <= n; i++) 
        v[i] = (v[i - 1] + v[i - 2]);
    cout << v[n];
    return 0;
}