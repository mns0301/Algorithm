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

int main() {
    fastio;

    int a[3] = { 0 };
    cin >> a[0] >> a[1] >> a[2];

    if (a[0]+a[1]+a[2] != 180) {
        cout << "Error";
        return 0;
    }
    if (a[0] == a[1] && a[1] == a[2] && a[2] == 60) {
        cout << "Equilateral";
        return 0;
    }
    if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) {
        cout << "Isosceles";
        return 0;
    }

    cout << "Scalene";
    return 0;
}