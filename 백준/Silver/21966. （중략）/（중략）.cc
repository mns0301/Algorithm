#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n;
    string str;
    cin >> n >> str;

    if (n <= 25)
        cout << str;
    else {
        int flag = 0;
        for (int i = 11; i < n - 12; i++) {
            if (str[i] == '.')
                flag = 1;
        }

        if (flag == 0) {
            for (int i = 0; i < 11; i++)
                cout << str[i];
            cout << "...";
            for (int i = n - 11; i < n; i++)
                cout << str[i];
        }
        else {
            for (int i = 0; i < 9; i++)
                cout << str[i];
            cout << "......";
            for (int i = n - 10; i < n; i++)
                cout << str[i];
        }
    }

    return 0;
}