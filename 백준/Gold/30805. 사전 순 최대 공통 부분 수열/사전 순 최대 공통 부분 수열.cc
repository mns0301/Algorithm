#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <deque>
#include <cmath>
using namespace std;

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
#define f(i, n) for(int i = 0; i < n; i++)

int n, m;
vi an, bn;
vi s_an, s_bn, temp;
int k;
int a, b;
int ai, bi;

void input();
void fun();
void output();

void input() {
    cin >> n;
    an.resize(n);
    for (int i = 0; i < n; i++) cin >> an[i];
    cin >> m;
    bn.resize(m);
    for (int i = 0; i < m; i++) cin >> bn[i];

    s_an = an;
    s_bn = bn;
    sort(s_an.begin(), s_an.end(), greater<int>());
    sort(s_bn.begin(), s_bn.end(), greater<int>());
}

void fun() {
    while (a < n && b < m) {
        if (s_an[a] > s_bn[b]) a++;
        else if (s_an[a] < s_bn[b]) b++;
        else {
			int x = -1, y = -1;
			for (int i = ai; i < n; i++) {
				if (s_an[a] == an[i]) {
					x = i;
					break;
				}
			}
			for (int i = bi; i < m; i++) {
				if (s_bn[b] == bn[i]) {
					y = i;
					break;
				}
			}
			if (x != -1 && y != -1) {
				temp.push_back(an[x]);
				ai = ++x;
				bi = ++y;
			}
            a++;
            b++;
        }
    }
}

void output() {
    cout << temp.size() << "\n";
	for (int i = 0; i < temp.size(); i++) cout << temp[i] << " ";
}

int main() {
    fastio;

    input();
    fun();
    output();

    return 0;
}