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

    int n, k, ans = 0;
    cin >> n >> k;
    vi mul(n, 0), cnt(k + 1, 0), order(k, 0);

    f(i, k) {
        cin >> order[i];
        cnt[order[i]]++;
    }

    if (n==1) {
        for (int i = 1; i < k; i++) {
            if (order[i] != order[i-1]) ans++;
        }
        cout << ans;
        return 0;
    }

    for (int i = 0; i < k; i++) {
        int now = order[i];
        vi::iterator iter = find(mul.begin(), mul.end(), now);
        if (iter == mul.end())
        {
            for (int j = 0; j < n; j++) {
                if (mul[j] == 0) {
                    mul[j] = now;
                    goto a;
                }
            }
            for (int j = 0; j < n; j++) {
                if (cnt[mul[j]] == 0) {
                    mul[j] = now;
                    ans++;
                    goto a;
                }
            }

            vi tmp(mul);
            int sz = n;
            for (int j = i + 1; j < k; j++) {
                vi::iterator iter_tmp = find(tmp.begin(), tmp.end(), order[j]);
                if (iter_tmp != tmp.end()) {
                    *iter_tmp = 0;
                    sz--;
                }

                if (sz == 1) {
                    for (int l = 0; l < n; l++) {
                        if (tmp[l] != 0) {
                            mul[l] = now;
                            ans++;
                            goto a;
                        }
                    }
                }
            }
        }
        a:
            cnt[now]--;
    }

    cout << ans;

    return 0;
}