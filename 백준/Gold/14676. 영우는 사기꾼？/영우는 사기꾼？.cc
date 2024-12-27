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

    int n, m, k;
    cin >> n >> m >> k;
    vi deg(n + 1, 0);
    vvi topo(n + 1);
    vi build(n + 1, 0);

    f(i, m) {
        int x, y;
        cin >> x >> y;
        topo[y].push_back(x);
        deg[y]++;
    }

    int is_possible = 1;

    f(i, k) {
        int order, num;
        cin >> order >> num;

        if (order == 1) {
            f(i, deg[num]) {
                if (build[topo[num][i]] == 0) {
                    is_possible = 0;
                    break;
                }
            }

            if (is_possible) 
                build[num]++;
            else
                break;
        }
        else {
            build[num]--;

            if (build[num] < 0) {
                is_possible = 0;
                break;
            }
        }
    }

    if (is_possible)
        cout << "King-God-Emperor";
    else
        cout << "Lier!";

            return 0;
}