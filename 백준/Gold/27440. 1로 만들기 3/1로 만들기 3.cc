#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<long long, int> m;

int main() {
    long long n;
    cin >> n;
    queue<long long> q;
    q.push(n);
    m[n] = 0;
    while(!q.empty()) {
        long long x = q.front();
        q.pop();

        if(x == 1) {
            cout << m[1];
            return 0;
        }

        if(x % 2 == 0 && m.find(x / 2) == m.end()) {
            m[x / 2] = m[x] + 1;
            q.push(x / 2);
        }

        if(x % 3 == 0 && m.find(x / 3) == m.end()) {
            m[x / 3] = m[x] + 1;
            q.push(x / 3);
        }

        if(m.find(x - 1) == m.end()) {
            m[x - 1] = m[x] + 1;
            q.push(x - 1);
        }
    }
}