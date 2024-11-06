#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
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
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)

int main() {
    fastio;

    int n, cnt = 0;
    cin >> n;
    vpll pos(n);
    f(i, n) cin >> pos[i].first >> pos[i].second;

    for (int i = 0; i < n; i++) {
        ll p1_x = pos[i].first;
        ll p1_y = pos[i].second;
        for (int j = i + 1; j < n; j++) {
            ll p2_x = pos[j].first;
            ll p2_y = pos[j].second;
            for (int k = j + 1; k < n; k++) {
                ll p3_x = pos[k].first;
                ll p3_y = pos[k].second;

                ll len1 = (p1_x - p2_x) * (p1_x - p2_x) + (p1_y - p2_y) * (p1_y - p2_y);
                ll len2 = (p2_x - p3_x) * (p2_x - p3_x) + (p2_y - p3_y) * (p2_y - p3_y);
                ll len3 = (p3_x - p1_x) * (p3_x - p1_x) + (p3_y - p1_y) * (p3_y - p1_y);
                if (len1 < len2)
                    swap(len1, len2);
                if (len1 < len3)
                    swap(len1, len3);

                if (len1 == len2+len3)
                    cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}