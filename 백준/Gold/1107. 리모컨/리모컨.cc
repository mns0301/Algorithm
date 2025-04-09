#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;

    int n, x, t;
    cin >> n >> x;
    int ans = abs(100 - n);
    vector<int> s, v;
    while (x--) {
        cin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end());
    s.push_back(-1);
    x++;
    for (int i = 0; i < 10; i++) {
        if (i == s[x]) {
            x++;
            continue;
        }
        v.push_back(i);
    }

        int tmp = 0;
    for (int f : v) {
        tmp += f;
        ans = min(ans, abs(tmp - n) + 1);
        tmp -= f;
    }
    for (int e : v) {
        tmp += e * 10;
        for (int f : v) {
            tmp += f;
            ans = min(ans, abs(tmp - n) + 2);
            tmp -= f;
        }
        tmp -= e * 10;
    }
    for (int d : v) {
        tmp += d * 100;
        for (int e : v) {
            tmp += e * 10;
            for (int f : v) {
                tmp += f;
                ans = min(ans, abs(tmp - n) + 3);
                tmp -= f;
            }
            tmp -= e * 10;
        }
        tmp -= d * 100;
    }
    for (int c : v) {
        tmp += c * 1000;
        for (int d : v) {
            tmp += d * 100;
            for (int e : v) {
                tmp += e * 10;
                for (int f : v) {
                    tmp += f;
                    ans = min(ans, abs(tmp - n) + 4);
                    tmp -= f;
                }
                tmp -= e * 10;
            }
            tmp -= d * 100;
        }
        tmp -= c * 1000;
    }
    for (int b : v) {
        tmp += b * 10000;
        for (int c : v) {
            tmp += c * 1000;
            for (int d : v) {
                tmp += d * 100;
                for (int e : v) {
                    tmp += e * 10;
                    for (int f : v) {
                        tmp += f;
                        ans = min(ans, abs(tmp - n) + 5);
                        tmp -= f;
                    }
                    tmp -= e * 10;
                }
                tmp -= d * 100;
            }
            tmp -= c * 1000;
        }
        tmp -= b * 10000;
    }
    for (int a : v) {
        tmp += a * 100000;
        for (int b : v) {
            tmp += b * 10000;
            for (int c : v) {
                tmp += c * 1000;
                for (int d : v) {
                    tmp += d * 100;
                    for (int e : v) {
                        tmp += e * 10;
                        for (int f : v) {
                            tmp += f;
                            ans = min(ans, abs(tmp - n) + 6);
                            tmp -= f;
                        }
                        tmp -= e * 10;
                    }
                    tmp -= d * 100;
                }
                tmp -= c * 1000;
            }
            tmp -= b * 10000;
        }
        tmp -= a * 100000;
    }
    cout << ans;

    return 0;
}