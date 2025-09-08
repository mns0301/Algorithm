#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

void push();
void pop();
int calc();

int n, k, d, s, e, ans;
int algo[31];
vector<vector<int>> stu;

int main() {
	fastio;

    cin >> n >> k >> d;
    stu.resize(n);
    for (int i = 0; i < n; i++) {
        int m, x;
        cin >> m >> x;
        stu[i].resize(m + 1);
        stu[i][0] = x;
        for (int j = 1; j <= m; j++)
            cin >> stu[i][j];
    }
    sort(stu.begin(), stu.end());

    while (e < n) {
        if (stu[e][0] - stu[s][0] <= d) {
            push();
            e++;
        } else {
            ans = max(calc(), ans);
            pop();
            s++;
        }
    }
    ans = max(calc(), ans);
    cout << ans;

    return 0;
}

void push() {
    for (int i = 1; i < stu[e].size(); i++) {
        algo[stu[e][i]]++;
    }
}
void pop() {
    for (int i = 1; i < stu[s].size(); i++) {
        algo[stu[s][i]]--;
    }
}
int calc() {
    int tmp = 0;
    for (int i = 1; i <= k; i++) {
		if (0 < algo[i] && algo[i] < e - s)
            tmp++;
    }
    return tmp * (e - s);
}