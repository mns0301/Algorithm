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

void fun() {
    ll n_hp, s_hp;
    ll n_atk, n_heal, s_atk, s_heal;
    cin >> n_hp >> s_hp;
    cin >> n_atk >> n_heal >> s_atk >> s_heal;

    if (n_atk >= s_hp) {
        cout << "NARUTO\n";
        return;
    }
    if (s_atk >= n_heal + n_hp) {
        cout << "SASUKE\n";
        return;
    }

    if (s_heal >= n_atk && n_heal >= s_atk) {
        cout << "DRAW\n";
        return;
    }
    if (s_heal < n_atk && n_heal < s_atk) {
        if (ceil((double)s_hp / n_atk) > ceil((double)n_hp / s_atk)) {
            cout << "SASUKE\n";
            return;
        }
        else {
            cout << "NARUTO\n";
            return;
        }
    }
    else if (s_heal < n_atk) {
        if (s_atk < n_heal) {
            cout << "NARUTO\n";
            return;
        }
        else {
            if (ceil((double)s_hp / n_atk) <= ceil((double)n_hp / s_atk))
            {
                cout << "NARUTO\n";
                return;
            }
            else
            {
                cout << "DRAW\n";
                return;
            }
        }
    }
    else if (n_heal < s_atk) {
        if (n_atk < s_heal) {
            cout << "SASUKE\n";
            return;
        }
        else {
            if (ceil((double)s_hp / n_atk) > ceil((double)n_hp / s_atk))
            {
                cout << "SASUKE\n";
                return;
            }
            else
            {
                cout << "DRAW\n";
                return;
            }
        }
    }
    else {
        if (ceil((double)s_hp / n_atk) > ceil((double)n_hp / s_atk))
        {
            cout << "SASUKE\n";
            return;
        }
        else
        {
            cout << "NARUTO\n";
            return;
        }
    }
}

int main() {
    fastio;

    int t;
    cin >> t;
    w(t) fun();

    return 0;
}