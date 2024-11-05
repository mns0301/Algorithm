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

    int n, min_size = INT_MAX;
    cin >> n;
    vpii xy(n);
    vi set_x(n), set_y(n);

    f(i, n) {
        int y, x;
        cin >> x >> y;
        xy[i] = { y, x };
        set_x[i] = x;
        set_y[i] = y;
    }
    
    sort(set_x.begin(), set_x.end());
    sort(set_y.begin(), set_y.end());
    sort(xy.begin(), xy.end());

    for (int y1 = 0; y1 < n; y1++) {
        int y_min = set_y[y1];
        for (int y2 = y1; y2 < n; y2++) {
            int y_max = set_y[y2];
            for (int x1 = 0; x1 < n; x1++) {
                int x_min = set_x[x1];
                for (int x2 = x1; x2 < n; x2++) {
                    int x_max = set_x[x2];
                    int cnt = 0;
                    
                    // for (int k = 0; k < n; k++) {
                    //     int x = xy[k].second;
                    //     int y = xy[k].first;
                    //     if (y_min <= y && y <= y_max && x_min <= x && x <= x_max)
                    //         cnt++;
                    // }
                    for (int k = y1; k <= y2; k++) {
                        int x = xy[k].second;
                        if (x_min <= x && x <= x_max)
                            cnt++;
                    }
                    if (cnt >= n / 2)
                        min_size = min(min_size, (y_max - y_min + 2) * (x_max - x_min + 2));
                }
            }
        }
    }

    cout << min_size;

    return 0;
}