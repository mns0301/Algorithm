#include <iostream>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int fun(string a, string b) {
    int tmp = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            tmp++;
    }
    return tmp;
}

int main() {
    fastio;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string a, b;
        cin >> a >> b;
        cout << "Hamming distance is " << fun(a, b) << ".\n";
    }

        return 0;
}