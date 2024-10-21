#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <cmath>
#include <map>
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

ll t = 1000000;
vi is_prime(t + 1, 1);
vi p;
int n, cnt, gcd = 1;
vi v, tmp, x;
map<int, int> m;

void prime() {
	for (ll i = 2; i <= t; i++) {
		if (is_prime[i] == 0) continue;
		else p.push_back(i);

		for (ll j = i * i; j <= t; j += i) is_prime[j] = 0;
	}
}

void input() {
	cin >> n;
	v.resize(n);
	f(i, n) cin >> v[i];
}

void fun() {
	tmp = v;
	f(i, tmp.size()) {
		f(j, p.size()) {
			if (tmp[i] % p[j] == 0) {
				m[p[j]]++;
				tmp[i] /= p[j];
				j--;
			}
		}
	}
	for (auto& i : m) {
		while (i.second >= n) {
			gcd *= i.first;
			i.second -= n;
			x.push_back(i.first);
		}
	}
	f(i, v.size()) {
		f(j, x.size()) {
			if (v[i] % x[j] == 0) v[i] /= x[j];
			else cnt++;
		}
	}

}

void output() {
	cout << gcd << " " << cnt;
}

int main() {
	fastio;

	prime();
	input();
	fun();
	output();

	return 0;
}