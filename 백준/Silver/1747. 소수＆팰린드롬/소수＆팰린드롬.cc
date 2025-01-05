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

int N = 2000000;
vl is_prime(N, 1);
vl primes;

void primechk() {
    is_prime[0] = 0;
    is_prime[1] = 0;

    for (ll i = 2; i <= N; i++) {
        if (is_prime[i] == 0) continue;

        primes.push_back(i);
        for (ll j = i * i; j <= N; j += i) {
            is_prime[j] = 0;
        }
    }
}

int main() {
    fastio;

    primechk();

    int n;
    cin >> n;
    int i = 0;

    while (1) {
        if (primes[i++] < n) continue;
        i--;
        string str = to_string(primes[i]);
        int flag = 1;
        for (int j = 0; j < str.size() / 2; j++) {
            if (str[j] != str[str.size()-1-j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << str;
            break;
        }
        i++;
    }

    return 0;
}