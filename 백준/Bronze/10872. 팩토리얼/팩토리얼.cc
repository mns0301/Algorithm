#include <iostream>

int main() {
    long long a;
    std::cin >> a;
    long long t = 1;
    while (a--) t *= a+1;
    std::cout << t;
}