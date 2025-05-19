#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

int n, m;
vector<vector<int>> schedule(5, vector<int>(24, 0));
vector<int> c, s;
vector<vector<pair<int, int>>> lecture;
map<string, int> match_day;
int flag = 0;

int dfs(int idx, int sum,vector<vector<int>> &schedule) {
    if (flag || sum >= m) {
        flag = 1;
        return 1;
    }
    if (idx == n)
        return 0;

    int tmp = 1;
    for (auto [cur_day, cur_time] : lecture[idx]) {
        if (schedule[cur_day][cur_time] == 1) {
            tmp = 0;
            break;
        }
    }

    dfs(idx + 1, sum, schedule);
    if (tmp == 0) {
        return 0;
    } 
    else {
        for (auto [cur_day, cur_time] : lecture[idx]) {
            schedule[cur_day][cur_time] = 1;
        }
        dfs(idx + 1, sum + c[idx], schedule);
        for (auto [cur_day, cur_time] : lecture[idx]) {
            schedule[cur_day][cur_time] = 0;
        }
    }

    return 0;
}

int main() {
    fastio;

    cin >> n >> m;
    c.resize(n);
    s.resize(n);
    lecture.resize(n);
    match_day["MON"] = 0;
    match_day["TUE"] = 1;
    match_day["WED"] = 2;
    match_day["THU"] = 3;
    match_day["FRI"] = 4;

    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
        lecture[i].resize(s[i]);

        for (int j = 0; j < s[i]; j++) {
            string day;
            int time;
            cin >> day >> time;
            lecture[i][j] = { match_day[day], time };
        }
    }

    dfs(0, 0, schedule);
    cout << (flag ? "YES" : "NO");

    return 0;
}