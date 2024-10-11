#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
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
vvi v(20, vi(20));

void fun(vvi v, int cnt);

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}
}

void fun_up(vvi v, int cnt) {
	for (int i = 0; i < n; i++) {
		int index = 0;
		int can_mix = 0;
		for (int j = 0; j < n; j++) {
			if (v[j][i] != 0) {
				if (can_mix && v[index - 1][i] == v[j][i]) {
					v[index - 1][i] *= 2;
					can_mix = 0;
				}
				else {
					v[index++][i] = v[j][i];
					can_mix = 1;
				}
			}
		}
		for (int j = index; j < n; j++) v[j][i] = 0;
	}

	fun(v, cnt + 1);
}
void fun_down(vvi v, int cnt) {
	for (int i = 0; i < n; i++) {
		int index = n - 1;
		int can_mix = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (v[j][i] != 0) {
				if (can_mix && v[index + 1][i] == v[j][i]) {
					v[index + 1][i] *= 2;
					can_mix = 0;
				}
				else {
					v[index--][i] = v[j][i];
					can_mix = 1;
				}
			}
		}
		for (int j = 0; j <= index; j++) v[j][i] = 0;
	}

	fun(v, cnt + 1);
}
void fun_left(vvi v, int cnt) {
	for (int i = 0; i < n; i++) {
		int index = 0;
		int can_mix = 0;
		for (int j = 0; j < n; j++) {
			if (v[i][j] != 0) {
				if (can_mix && v[i][index - 1] == v[i][j]) {
					v[i][index - 1] *= 2;
					can_mix = 0;
				}
				else {
					v[i][index++] = v[i][j];
					can_mix = 1;
				}
			}
		}
		for (int j = index; j < n; j++) v[i][j] = 0;
	}

	fun(v, cnt + 1);
}
void fun_right(vvi v, int cnt) {
	for (int i = 0; i < n; i++) {
		int index = n - 1;
		int can_mix = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (v[i][j] != 0) {
				if (can_mix && v[i][index + 1] == v[i][j]) {
					v[i][index + 1] *= 2;
					can_mix = 0;
				}
				else {
					v[i][index--] = v[i][j];
					can_mix = 1;
				}
			}
		}
		for (int j = 0; j <= index; j++) v[i][j] = 0;
	}

	fun(v, cnt + 1);
}

void fun(vvi v, int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) m = max(v[i][j], m);
		}
		return;
	}

	fun_up(v, cnt);
	fun_down(v, cnt);
	fun_left(v, cnt);
	fun_right(v, cnt);
}

void output() {
	cout << m;
}

int main() {
	fastio;

	input();
	fun(v, 0);
	output();

	return 0;
}
