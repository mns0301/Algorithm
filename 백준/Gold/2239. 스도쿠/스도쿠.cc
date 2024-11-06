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

vvi sdk(9, vi(9));
vvi x(9, vi(10)), y(9, vi(10));
vector<vector<vector<int>>> m(3, vvi(3, vi(10)));
int cnt = 0;

void input() {
    f(i, 9) {
        string str;
        cin >> str;
        f(j, 9) sdk[i][j] = str[j] - '0';
    }
    f(i, 9) {
        f(j, 9) {
            if (sdk[i][j] == 0) continue;

            y[i][sdk[i][j]] = 1;
            x[j][sdk[i][j]] = 1;
            m[i / 3][j / 3][sdk[i][j]] = 1;
            cnt++;
        }
    }
}

void output() {
    f(i, 9) {
        f(j, 9) cout << sdk[i][j];
        cout << "\n";
    }
}

void fun(int i, int j) {
    if (cnt == 81) {
        output();
        exit(0);
    }
    
    if (i==9)
        return;
    else if (j==9)
        fun(i + 1, 0);
    else if (sdk[i][j]) 
        fun(i, j + 1);
    else if (sdk[i][j] == 0) {
        for (int k = 1; k < 10; k++) {
            if (y[i][k] == 0 && x[j][k] == 0 && m[i/3][j/3][k] == 0) {
                y[i][k] = 1;
                x[j][k] = 1;
                m[i / 3][j / 3][k] = 1;
                sdk[i][j] = k;
                cnt++;
                fun(i, j + 1);
                y[i][k] = 0;
                x[j][k] = 0;
                m[i / 3][j / 3][k] = 0;
                sdk[i][j] = 0;
                cnt--;
            }
        }
    }
}

int main() {
    fastio;

    input();
    fun(0, 0);
    //output();

    return 0;
}