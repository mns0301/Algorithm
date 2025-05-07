#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

vector<pair<double, double>> find_cen(pair<double, double> &v1, pair<double, double> &v2, double dist) {
    double dy = v1.first - v2.first;
    double dx = v1.second - v2.second;
    double my = (v1.first + v2.first) / 2;
    double mx = (v1.second + v2.second) / 2;
    double line = sqrt(1.0 - (dist * dist / 4.0));
    double ux = -dy / dist;
    double uy = dx / dist;

    vector<pair<double, double>> tmp;
    tmp.push_back({ my + uy * line, mx + ux * line });
    tmp.push_back({ my - uy * line, mx - ux * line });
    return tmp;
}

double dis(pair<double, double> &v1, pair<double, double> &v2) {
    double dis = (v2.first - v1.first) * (v2.first - v1.first) + (v2.second - v1.second) * (v2.second - v1.second);
    return sqrt(dis);
}

int main() {
    fastio;

    while(1) {
        int n;
        cin >> n;
        if (n==0)
            break;

        vector<pair<double, double>> v(n);
        int m = 1;
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                double dist = dis(v[i], v[j]);
                if (dist > 2.0002) continue;
                vector<pair<double, double>> cen = find_cen(v[i], v[j], dist);
                
                int tmp = 0;
                for (int k = 0; k < n; k++) {
                    dist = dis(cen[0], v[k]);
                    if (dist <= 1.0001)
                        tmp++;
                }
                m = max(tmp, m);

                tmp = 0;
                for (int k = 0; k < n; k++) {
                    dist = dis(cen[1], v[k]);
                    if (dist <= 1.0001)
                        tmp++;
                }
                m = max(tmp, m);
            }
        }

        cout << m << "\n";
    }

    return 0;
}