#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int minX, minY, maxX, maxY;
int ans = 1e9;

bool inBox(array<int ,3> tree) {
    int x = tree[0], y = tree[1];
    if ((minX <= x && x <= maxX) && (minY <= y && y <= maxY)) return 1;
    return 0;
}

int main() {
    fastio;

    int n;
    cin >> n;
    vector<array<int, 3>> v;
    vector<int> x;
    vector<int> y;
    vector<array<int, 2>> ordered;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ a, b, c });
        x.push_back(a);
        y.push_back(b);
        ordered.push_back({ c, i });
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(ordered.begin(), ordered.end(), greater<>());

    for (int x1 = 0; x1 < n; x1++) {
        for (int x2 = x1; x2 < n; x2++) {
            for (int y1 = 0; y1 < n; y1++) {
                for (int y2 = y1; y2 < n; y2++) {
                    minX = x[x1], minY = y[y1], maxX = x[x2], maxY = y[y2];
                    int s = 0, side = (maxX - minX + maxY - minY) << 1, cnt = 0;
                    int arr[40] = { 0 };
                    for (int i = 0; i < n; i++) {
                        arr[i] = inBox(v[i]);
                        if (!arr[i]) {
                            s += v[i][2];
                            cnt++;
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        if (s >= side)
                            break;

                        if (arr[ordered[i][1]]) {
                            s += ordered[i][0];
                            cnt++;
                        }
                    }

                    ans = min(ans, cnt);
                }
            }
        }
    }

    cout << ans;

    return 0;
}