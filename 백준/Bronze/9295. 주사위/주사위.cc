#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <deque>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define str string
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define f(i, n) for(int i = 0; i < n; i++)

int main() {
    fastio;

    int t, a, b;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << "Case " << i << ": " << a+b << "\n";
    }

    return 0;
}