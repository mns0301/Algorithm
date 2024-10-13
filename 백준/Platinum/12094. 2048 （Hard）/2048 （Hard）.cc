#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <deque>
#include <cstring>
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
ll m;
ll v[21][21];

void fun(ll v[21][21], int cnt, array<int, 4> a);
void fun_up(ll v[21][21], int cnt, array<int, 4> a);
void fun_down(ll v[21][21], int cnt, array<int, 4> a);
void fun_right(ll v[21][21], int cnt, array<int, 4> a);
void fun_left(ll v[21][21], int cnt, array<int, 4> a);
void find_max(ll v[21][21]);

void print_board(ll v[21][21]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-------------------\n";
}


void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}
}

void fun_up(ll v[21][21], int cnt, array<int, 4> a) {
	ll temp_max = 0;
	ll tmp[21][21];
	memcpy(tmp, v, sizeof(tmp));
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		int index = 0;
		int can_mix = 0;
		for (int j = 0; j < n; j++) {
			if (v[j][i]) {
				if (can_mix && v[index - 1][i] == v[j][i]) {
					v[index - 1][i] <<= 1;
					temp_max = max(temp_max, v[index - 1][i]);
					can_mix = 0;
					a[0] = 1;
				}
				else {
					temp_max = max(temp_max, v[j][i]);
					v[index++][i] = v[j][i];
					can_mix = 1;
				}
			}
		}
		for (int j = index; j < n; j++) v[j][i] = 0;
	}
	// if (a[0] == 0) {
	// 	f(i, n) {
	// 		f(j, n) {
	// 			if (v[i][j] != tmp[i][j]) goto chk1;
	// 		}
	// 	}
	// 	m = max(temp_max, m);
	// 	return;
	// }
	// chk1:
	if (temp_max << (9 - cnt) <= m) return;
	a = {a[0], 1, 1, 1};
	//a = {1, 1, 1, 1};
	fun(v, cnt + 1, a);
}
void fun_down(ll v[21][21], int cnt, array<int, 4> a) {
	ll temp_max = 0;
	ll tmp[21][21];
	memcpy(tmp, v, sizeof(tmp));
	a[1] = 0;
	for (int i = 0; i < n; i++) {
		int index = n - 1;
		int can_mix = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (v[j][i]) {
				if (can_mix && v[index + 1][i] == v[j][i]) {
					v[index + 1][i] <<= 1;
					temp_max = max(temp_max, v[index + 1][i]);
					can_mix = 0;
					a[1] = 1;
				}
				else {
					temp_max = max(temp_max, v[j][i]);
					v[index--][i] = v[j][i];
					can_mix = 1;
				}
			}
		}
		for (int j = 0; j <= index; j++) v[j][i] = 0;
	}
	// if (a[1] == 0) {
	// 	f(i, n) {
	// 		f(j, n) {
	// 			if (v[i][j] != tmp[i][j]) goto chk2;
	// 		}
	// 	}
	// 	m = max(temp_max, m);
	// 	return;
	// }
	// chk2:
	if (temp_max << (9 - cnt) <= m) return;
	a = {1, a[1], 1, 1};
	//a = {1, 1, 1, 1};
	fun(v, cnt + 1, a);
}
void fun_left(ll v[21][21], int cnt, array<int, 4> a) {
	ll temp_max = 0;
	ll tmp[21][21];
	memcpy(tmp, v, sizeof(tmp));
	a[2] = 0;
	for (int i = 0; i < n; i++) {
		int index = 0;
		int can_mix = 0;
		for (int j = 0; j < n; j++) {
			if (v[i][j]) {
				if (can_mix && v[i][index - 1] == v[i][j]) {
					v[i][index - 1] <<= 1;
					temp_max = max(temp_max, v[i][index - 1]);
					can_mix = 0;
					a[2] = 1;
				}
				else {
					temp_max = max(temp_max, v[i][j]);
					v[i][index++] = v[i][j];
					can_mix = 1;
				}
			}
		}
		for (int j = index; j < n; j++) v[i][j] = 0;
	}
	// if (a[2] == 0) {
	// 	f(i, n) {
	// 		f(j, n) {
	// 			if (v[i][j] != tmp[i][j]) goto chk3;
	// 		}
	// 	}
	// 	m = max(temp_max, m);
	// 	return;
	// }
	// chk3:
	if (temp_max << (9 - cnt) <= m) return;
	a = {1, 1, a[2], 1};
	//a = {1, 1, 1, 1};
	fun(v, cnt + 1, a);	
}
void fun_right(ll v[21][21], int cnt, array<int, 4> a) {
	ll temp_max = 0;
	ll tmp[21][21];
	memcpy(tmp, v, sizeof(tmp));
	a[3] = 0;
	for (int i = 0; i < n; i++) {
		int index = n - 1;
		int can_mix = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (v[i][j]) {
				if (can_mix && v[i][index + 1] == v[i][j]) {
					v[i][index + 1] <<= 1;
					temp_max = max(temp_max, v[i][index + 1]);
					can_mix = 0;
					a[3] = 1;
				}
				else {
					temp_max = max(temp_max, v[i][j]);
					v[i][index--] = v[i][j];
					can_mix = 1;
				}
			}
		}
		for (int j = 0; j <= index; j++) v[i][j] = 0;
	}
	// if (a[3] == 0) {
	// 	f(i, n) {
	// 		f(j, n) {
	// 			if (v[i][j] != tmp[i][j]) goto chk4;
	// 		}
	// 	}
	// 	m = max(temp_max, m);
	// 	return;
	// }
	// chk4:
	if (temp_max << (9 - cnt) <= m) return;
	a = {1, 1, 1, a[3]};
	//a = {1, 1, 1, 1};
	fun(v, cnt + 1, a);
}

void fun(ll v[21][21], int cnt, array<int, 4> a) {
	if (cnt == 10) {
		find_max(v);
		return;
	}
	

	ll tmp[21][21];
	if (a[0]) {
		memcpy(tmp, v, sizeof(tmp));
		fun_up(tmp, cnt, a);
	}
	if (a[1]) {
		memcpy(tmp, v, sizeof(tmp));
		fun_down(tmp, cnt, a);
	}
	if (a[2]) {
		memcpy(tmp, v, sizeof(tmp));
		fun_left(tmp, cnt, a);
	}
	if (a[3]) {
		memcpy(tmp, v, sizeof(tmp));
		fun_right(tmp, cnt, a);
	}
}

void find_max(ll v[21][21]) {
	f(i, n) {
		f(j, n) m = max(v[i][j], m);
	}
}

void output() {
	cout << m;
}

int main() {
	fastio;

	input();
	fun(v, 0, {1,1,1,1});
	output();

	return 0;
}
