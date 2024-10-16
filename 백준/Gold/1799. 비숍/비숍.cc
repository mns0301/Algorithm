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

int n;
vvi v;
int max_cnt1, max_cnt2;
vi crs1, crs2;
vpii pos1, pos2;

void input();
void fun(int cnt, int i);
void output();

void input() {
    cin >> n;
    v.resize(n);
    f(i, n) v[i].resize(n);
    crs1.resize(2 * n);
    crs2.resize(2 * n);

    f(i, n) {
        f(j, n) {
			cin >> v[i][j];
			if (v[i][j]) {
				if ((i+j)%2) pos1.push_back({i, j});
				else pos2.push_back({i, j});
			}
		}
    }
}

void fun1(int cnt, int x) {
	max_cnt1 = max(cnt, max_cnt1);
    for (x; x < pos1.size(); x++) {
		int i = pos1[x].first;
		int j = pos1[x].second;
		if (crs1[n-i-1 + j] || crs2[i + j]) continue;

		crs1[n-i-1 + j] = 1;
		crs2[i + j] = 1;
		fun1(cnt + 1, x + 1);
		crs1[n-i-1 + j] = 0;
		crs2[i + j] = 0;
	}
}

void fun2(int cnt, int x) {
	max_cnt2 = max(cnt, max_cnt2);
    for (x; x < pos2.size(); x++) {
		int i = pos2[x].first;
		int j = pos2[x].second;
		if (crs1[n-i-1 + j] || crs2[i + j]) continue;

		crs1[n-i-1 + j] = 1;
		crs2[i + j] = 1;
		fun2(cnt + 1, x + 1);
		crs1[n-i-1 + j] = 0;
		crs2[i + j] = 0;
	}
}

void output() {
    cout << max_cnt1 + max_cnt2;
}

int main() {
    fastio;

    input();
    fun1(0, 0);
	fun2(0, 0);
    output();

    return 0;
}