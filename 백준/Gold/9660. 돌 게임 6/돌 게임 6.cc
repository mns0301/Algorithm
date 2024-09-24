#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin >> n;
    n %= 7;
    cout << ((n == 0 || n == 2) ? "CY" : "SK");

    return 0;
}