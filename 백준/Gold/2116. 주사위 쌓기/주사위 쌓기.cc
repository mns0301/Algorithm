#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int find_nxt(int n, int i, int s);
int find_max(int n, int i);
int find_top(int i);

vector<vector<int>> dice;
int N;

int find_nxt(int n, int i, int s) {
    if (n + 1 == N)
        return s;

    int top = find_top(i);
    for (int nxt = 0; nxt < 6; nxt++) {
        if (dice[n][top] == dice[n + 1][nxt]) {
            return find_nxt(n + 1, nxt, s + find_max(n + 1, nxt));
        }
    }
}

int find_top(int i) {
    int top;
    if (i == 0)
        top = 5;
    else if (i == 1)
        top = 3;
    else if (i == 2)
        top = 4;
    else if (i == 3)
        top = 1;
    else if (i == 4)
        top = 2;
    else
        top = 0;

    return top;
}

int find_max(int n, int i) {
    int top = find_top(i);

    int tmp = 0;
    for (int m = 0; m < 6; m++) {
        if (m == i || m == top) continue;
        tmp = max(tmp, dice[n][m]);
    }
    return tmp;
}

int main() {
    fastio;
    
    cin >> N;
    dice.resize(N);

    for (int i = 0; i < N; i++) {
        dice[i].resize(6);
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        dice[i] = { a, b, c, d, e, f };
    }

    int chk = 0;
    for (int idx_under = 0; idx_under < 6; idx_under++) 
        chk = max(chk, find_nxt(0, idx_under, find_max(0, idx_under)));

    cout << chk << "\n";
    return 0;
}