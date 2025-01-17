#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    vector<int> n;
    vector<int> p;
    int z = 0;
    int N, t;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t > 0)
            p.push_back(t);
        else if (t < 0)
            n.push_back(t);
        else
            z++;
    }
    sort(p.begin(), p.end(), greater<int>());
    sort(n.begin(), n.end());

    deque<int> dp, dn;

    for (int i = 0; i < p.size(); i++) {
        if (i % 2)
            dp.push_back(p[i]);
        else
            dp.push_front(p[i]);
    }

    for (int i = 0; i < n.size(); i++)
    {
        if (i % 2)
            dn.push_back(n[i]);
        else
            dn.push_front(n[i]);
    }

    while (dn.size()) {
        if (n.size() % 2) {
            cout << dn.back() << " ";
            dn.pop_back();
        }
        else {
            cout << dn.front() << " ";
            dn.pop_front();
        }
    }
    for (int i = 0; i < z; i++)
        cout << "0 ";

    while (dp.size()) {
        if (p.size() % 2) {
            cout << dp.front() << " ";
            dp.pop_front();
        }
        else {
            cout << dp.back() << " ";
            dp.pop_back();
        }
    }

        return 0;
}