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

int d = 1;
void color() {
    if (d == 1)
        d = 2;
    else if (d == 2)
        d = 1;
}

int main() {
    fastio;

    int n;
    cin >> n;
    int m = n*(n+1)+n;

    cout << m << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << d << " " << j << "\n";
        }
        color();
    }

    for (int i = 1; i <= n; i++) {
        cout << d << " " << i << "\n";
    }
    color();

    for (int i = n; i > 0; i--) {
        for (int j = n - i + 1; j <= n; j++) {
            cout << d << " " << j << "\n";
        }
        color();
    }

        return 0;
}