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

    string str;
    cin >> str;
    int cnt = 0;

    f(i, str.size()) {
        if (str[i] == 'X') {
            cnt++;
        }
        else {
            if (cnt == 2) {
                str[i - 1] = 'B';
                str[i - 2] = 'B';
            }
            cnt = 0;
        }
        if (cnt == 4) {
            cnt = 0;
            str[i] = 'A';
            str[i - 1] = 'A';
            str[i - 2] = 'A';
            str[i - 3] = 'A';
        }
    }

    if (cnt == 4) {
        str[str.size()-1] = 'A';
        str[str.size() - 1 - 1] = 'A';
        str[str.size() - 1 - 2] = 'A';
        str[str.size() - 1 - 3] = 'A';
    }
    else if (cnt == 2)
    {
        str[str.size() - 1] = 'B';
        str[str.size() - 1 - 1] = 'B';
    }

    f(i, str.size()) {
        if (str[i] == 'X') {
            cout << -1;
            return 0;
        }
    }

        cout << str;

    return 0;
}