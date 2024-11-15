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

stack<char> s;
string str, boom;
stack<char> tmp;

void chk() {
    for (int i = boom.size() - 1; i >= 0; i--) {
		if (s.top() == boom[i]) {
            tmp.push(s.top());
            s.pop();
        }
		else {
			while (tmp.size()) {
                s.push(tmp.top());
                tmp.pop();
            }
            return;
        }
	}
	while (tmp.size()) {
        tmp.pop();
    }
}

int main() {
    fastio;

    cin >> str >> boom;

    f(i, str.size()) {
        s.push(str[i]);
        if (s.size() >= boom.size() && s.top() == boom[boom.size()-1]) {
            chk();
        }
	}

	if (s.empty())
        cout << "FRULA";
	else {
		while(s.size()) {
            tmp.push(s.top());
            s.pop();
        }
		while(tmp.size()) {
            cout << tmp.top();
            tmp.pop();
        }
	}

    return 0;
}