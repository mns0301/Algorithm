#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)

int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int n;

int chk(int num) {
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void prime(int num, int d) {
    if (d==n) {
        cout << num << "\n";
        return;
    }

    num *= 10;
    for (int i = 1; i < 10; i+=2) {
        if (chk(num + i))
            prime(num + i, d + 1);
    }
}

int main() {
    fastio;

    cin >> n;

    if (n==1) {
        cout << "2\n3\n5\n7\n";
        return 0;
    }

    prime(2, 1);
    prime(3, 1);
    prime(5, 1);
    prime(7, 1);

    return 0;
}