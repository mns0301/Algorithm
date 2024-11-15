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

    stack<char> s;

    int n, k;
    cin >> n >> k;

    char tmp;
    cin >> tmp;
    s.push(tmp);
    n--;

    f(i, n) {
        cin >> tmp;
        while(s.size() && s.top() < tmp) {
            s.pop();
            k--;
            if (k==0)
                break;
        }
        s.push(tmp);
        if(k==0) {
            for (int j = i + 1; j < n; j++) {
                cin >> tmp;
                s.push(tmp);
            }
            break;
        }
    }

    while(k--) {
        s.pop();
    }

    stack<char> x;

    while(s.size()) {
        x.push(s.top());
        s.pop();
    }

    while(x.size()) {
        cout << x.top();
        x.pop();
    }

    return 0;
}