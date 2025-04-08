#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)



int main() {
    fastio;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++) 
            cout << '@';
        for (int j = 0; j < n; j++) 
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++) 
            cout << '@';
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << '@';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << '@';
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << '@';
        for (int j = 0; j < n; j++)
            cout << '@';
        for (int j = 0; j < n; j++)
            cout << '@';
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << '@';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << '@';
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << '@';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << '@';
        cout << "\n";
    }
        return 0;
}