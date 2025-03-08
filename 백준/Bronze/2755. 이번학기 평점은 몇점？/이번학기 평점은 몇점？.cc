#include <iostream>
#include <vector>
using namespace std;

float score(string str) {
    float t = 0;
    switch (str[0])
    {
    case 'A':
        t = 4;
        break;
    case 'B':
        t = 3;
        break;
    case 'C':
        t = 2;
        break;
    case 'D':
        t = 1;
        break;
    default:
        return 0.0;
    }

    switch (str[1])
    {
    case '+':
        t += 0.3;
        break;
    case '-':
        t -= 0.3;
        break;
    }

    return t;
}

int main() {
    int n;
    float x = 0, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str, sco;
        float a;
        cin >> str >> a >> sco;
        s += a * score(sco);
        x += a;
    }

    printf("%.2f", s / x);

    return 0;
} 