#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <map>
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

int main() {
    fastio;

    int g, p;
    cin >> g >> p;
    vector<int> chk(g + 1, 0);
    vector<int> target(p, 0);
    f(i, p) cin >> target[i];
    int cnt = 0;

    for (int i = 0; i < p; i++) {
        int now = target[i];
		if (chk[now] == 0) {
            chk[now] = now;
            cnt++;
        }
		else {
            int tmp = chk[now];

			while(--tmp) {
				if (chk[tmp] == 0) {
                    chk[now] = tmp;
                    chk[tmp] = tmp;
                    cnt++;
                    break;
                }
			}
			if (tmp == 0)
                break;
        }
    }
    // f(i, g + 1) cout << chk[i] << " ";
    // cout << "\n";

    cout << cnt;

    return 0;
}