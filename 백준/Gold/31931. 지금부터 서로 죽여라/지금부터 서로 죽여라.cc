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
    ll hp1, hp2, atk1, atk2, heal1, heal2;
    cin >> hp1 >> hp2 >> atk1 >> heal1 >> atk2 >> heal2;
    int win = 0;

    if (hp2 <= atk1)
        win = 1;
	else if (hp1+heal1 <= atk2)
        win = -1;
	else if (heal1 >= atk2 && heal2 >= atk1) {
        win = 0;
    }
	else if (atk1 > heal2 && atk2 > heal1) {
        if (ceil((double)hp1 / atk2) >= ceil((double)hp2 / atk1))
            win = 1;
		else
            win = -1;
    }
	else if (atk1 > heal2) {
        if (atk2 < heal1) 
            win = 1;
        else if (ceil((double)hp1 / atk2) >= ceil((double)hp2 / atk1))
            win = 1;
        else
            win = 0;
    }
    else if (atk2 > heal1) {
        if (atk1 < heal2)
            win = -1;
        else if (ceil((double)hp1 / atk2) < ceil((double)hp2 / atk1))
            win = -1;
        else
            win = 0;
    }
	else {
        win = 0;
    }

	if (win == 1)
        cout << "NARUTO\n";
	else if (win==-1)
        cout << "SASUKE\n";
	else
        cout << "DRAW\n";
}

int main() {
	fastio;
    
    int t;
    cin >> t;
    w(t) fun();

    return 0;
}