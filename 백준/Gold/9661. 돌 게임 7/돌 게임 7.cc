#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    n %= 5;
    cout << ((n == 2 || n == 0) ? "CY" : "SK");

    return 0;
}