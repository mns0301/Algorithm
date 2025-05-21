#include <iostream>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n;
    while(n--) {
        int tmp = 0;
        cin >> str;
        for (int i = 0; i + 2< str.size(); i++) {
            if (str[i] == 'W' && str[i+1] == 'O' && str[i+2] == 'W') tmp++;
        }
        cout << tmp << '\n';
    }
}