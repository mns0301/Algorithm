#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
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
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)

void input();
void fun();
void output();

int r, c, m;
vvi field;
vector<array<int, 3>> v;
int pos, score;

void input() {
	cin >> r >> c >> m;
	field.resize(r + 1);
	f(i, r+1) field[i].resize(c + 1);
	v.resize(m + 1);

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> y >> x;
		cin >> v[i][0] >> v[i][1] >> v[i][2];
		field[y][x] = i;
	}
}

pii move(int y, int x, int n) {
	int speed;
	int a;

	if (v[n][1] == 1 || v[n][1] == 2) {
		speed = v[n][0] % (2*r - 2);
		if (v[n][1] == 1) a = -1;
		else a = 1;
		while (speed--) {
			y+=a;
			if (y == 0) {
				y = 2;
				a = 1;
			}
			else if (y > r) {
				y = r-1;
				a = -1;
			}
		}
		if (a == 1) v[n][1] = 2;
		else v[n][1] = 1;
	}
	else {
		speed = v[n][0] % (2*c - 2);
		if (v[n][1] == 4) a = -1;
		else a = 1;
		while (speed--) {
			x+=a;
			if (x == 0) {
				x = 2;
				a = 1;
			}
			else if (x > c) {
				x = c-1;
				a = -1;
			}
		}
		if (a == 1) v[n][1] = 3;
		else v[n][1] = 4;
	}
	
	return {y, x};
}

void fun() {
	while (1) {
		pos++;
		if (pos > c) return;
		for (int i = 1; i <= r; i++) {
			if (field[i][pos]) {
				score += v[field[i][pos]][2];
				field[i][pos] = 0;
				break;
			}
		}

		vvi tmp(r+1, vi(c+1, 0));
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (field[i][j] == 0) continue;

				pii p = move(i, j, field[i][j]);
				if (v[tmp[p.first][p.second]][2] < v[field[i][j]][2]) tmp[p.first][p.second] = field[i][j];
			}
		}
		field = tmp;
	}
}

void output() {
	cout << score;
}

int main() {
	fastio;

	input();
	fun();
	output();

	return 0;
}