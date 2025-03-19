#include <iostream>
#include <vector>
#include <cmath>

typedef long long int ll;
using namespace std;

struct Point {
    ll x, y;
};

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    ll ans = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                ll dx1 = points[i].x - points[j].x;
                ll dy1 = points[i].y - points[j].y;
                ll dx2 = points[i].x - points[k].x;
                ll dy2 = points[i].y - points[k].y;
                ll dx3 = points[j].x - points[k].x;
                ll dy3 = points[j].y - points[k].y;

                ll d1 = dx1 * dx1 + dy1 * dy1;
                ll d2 = dx2 * dx2 + dy2 * dy2;
                ll d3 = dx3 * dx3 + dy3 * dy3;

                if (d1 + d2 == d3 || d1 + d3 == d2 || d2 + d3 == d1) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}
