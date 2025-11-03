#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
//#define int long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define loop(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define foreach(i, v) for(auto i : v)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

int dy8[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dx8[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
int dy4[4] = { 0, 0, -1, 1 };
int dx4[4] = { -1, 1, 0, 0 };

int sec;
int n;
vector<vector<int>> grid;

class Position {
    public:
        int row, col;
        Position(int row, int col) {
            this->row = row;
            this->col = col;
        }
        bool operator<(const Position &other) const {
            if (row != other.row)
                return row < other.row;
            return col < other.col;
        }
};

class Entity {
public:
    int row, col;
    int size;

    Entity() {
        row = 0;
        col = 0;
        size = 1;
    }
    Entity(int row, int col, int size = 2) {
        this->row = row;
        this->col = col;
        this->size = size;
    }
    Position getPos() {
        return Position(row, col);
    }
};
class Shark : public Entity {
    public:
        int exp;

        Shark() {
            exp = 0;
        }
        Shark(int row, int col) : Entity(row, col, 2) {
            exp = 0;
        }
        void eat(Entity fish) {
            if (size > fish.size) {
                grid[fish.row][fish.col] = 0;
                exp++;
                if (exp == size) {
                    size++;
                    exp = 0;
                }
            }
        }
        void setPosition(Position pos) {
            this->row = pos.row;
            this->col = pos.col;
        }
        int distance(Entity fish) {
            return abs(fish.row - row) + abs(fish.col - col);
        }
};

map<Position, Entity> fish;
Shark shark;

void input() {
    cin >> n;
    grid.resize(n + 2);
    f(i, n + 2) grid[i].resize(n + 2);
    f(i, n + 2) {
        grid[0][i] = 1;
        grid[n + 1][i] = 1;
        grid[i][0] = 1;
        grid[i][n + 1] = 1;
    }
    f1(r, n) {
        f1(c, n) {
            cin >> grid[r][c];
            if (grid[r][c]) {
                if (grid[r][c]==9) {
                    shark = Shark(r, c);
                    grid[r][c] = 0;
                } else {
                    fish[Position(r, c)] = Entity(r,c,grid[r][c]);
                    grid[r][c] = 2;
                }
            }
        }
    }
    sec = 0;
}

void find_fish(vector<pair<int, Entity>>& found) {
    vector<vector<int>> visited(n + 2, vector<int>(n + 2, 0));
    queue<pair<int, Position>> q;
    q.push({ 0, shark.getPos() });
    visited[shark.row][shark.col] = 1;

    while(q.size()) {
        int dis = q.front().first;
        Position cur = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            Position nxt(cur.row + dy4[i], cur.col + dx4[i]);
            if (visited[nxt.row][nxt.col] || grid[nxt.row][nxt.col] == 1) continue;
            visited[nxt.row][nxt.col] = 1;
            if (grid[nxt.row][nxt.col] == 2) {
                Entity tmp = fish[nxt];
                if (tmp.size <= shark.size) {
                    q.push({dis+1, nxt});
                    if (tmp.size < shark.size)
                        found.push_back({ dis + 1, tmp });
                }
            }
            else
                q.push({ dis + 1, nxt });
        }
    }
}

pair<int, Entity> select_fish(vector<pair<int, Entity>>& found) {
    Entity pre = found[0].second;
    int pre_dis = found[0].first;
    for (int i = 1; i < found.size(); i++) {
        Entity cur = found[i].second;
        int cur_dis = found[i].first;
        if (pre_dis > cur_dis) {
            pre_dis = cur_dis;
            pre = cur;
        }
        else if (pre_dis == cur_dis) {
            if (cur.getPos() < pre.getPos())
                pre = cur;
        }
    }
    return make_pair(pre_dis, pre);
}

void fun() {
    while (true)
    {
        vector<pair<int, Entity>> found;
        find_fish(found);
        if (found.empty())
            return;
        auto [dis, selected] = select_fish(found);
        shark.eat(selected);
        grid[selected.row][selected.col] = 0;
        sec += dis;
        shark.setPosition(selected.getPos());
    }
}

void output() {
    cout << sec << "\n";
}

int main() {
    fastio;

    input();
    fun();
    output();

    return 0;
}