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

#define INT_MAX 2147483647
#define INT_MIN -2147483648
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

vi is_prime(1000000, 1);

void find_prime() {
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i <= 1000000; i++) {
        if (is_prime[i] == 0) continue;

        for (int j = 2 * i; j <= 1000000; j += i) {
            is_prime[j] = 0;
        }
    }
}

int main() {
    fastio;

    int n, cnt = 0;
    cin >> n;
    int i = 0;
    find_prime();

    while (cnt != n)
    {
        if (is_prime[i] == 1) {
            cout << i << " ";
            cnt++;
        }
        i++;
    }

    return 0;
}