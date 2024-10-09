#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

vector<int> is_prime(4040404, 1);
vl prime;
ll n, cnt;

void Sieve()
{
	prime.push_back(0);
	for (ll i = 2; i <= n; i++)
	{
		if (is_prime[i] == 0) continue;
		prime.push_back(prime.back() + i);

		for (ll j = i * i; j <= n; j += i) is_prime[j] = 0;
	}
}

void fun() {
	for (int i = 0; i < prime.size(); i++) {
		for (int j = i; j < prime.size(); j++) {
			ll temp = prime[j] - prime[i];
			
			if (temp > n) break;
			
			if (temp == n) cnt++;
			
		}
	}
}

int main() {
	fastio;

	cin >> n;

	Sieve();
	fun();
	cout << cnt;
	return 0;
}
