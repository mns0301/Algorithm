#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long

#define row first
#define col second
#define EMPTY 0
#define WALL 1
#define APPLE 2

int n, k, l, current_time = 0;
vector<vector<int>> field(102, vector<int>(102, 0));
queue<pair<int, char>> rotateInfo;
pair<int, int> current;
queue<pair<int, int>> path;
char direction;

void move() {
	switch (direction)
	{
	case 'R':
        current.col++;
        break;
    case 'L':
        current.col--;
        break;
    case 'U':
        current.row--;
        break;
    case 'D':
        current.row++;
        break;
	}
	path.push(current);
}

int current_pos() {
    return field[current.row][current.col];
}
void setCurrent(int item) {
    field[current.row][current.col] = item;
}
void reduceTail() {
    field[path.front().row][path.front().col] = EMPTY;
    path.pop();
}

bool isCollision() {
    return (current_pos() == WALL ? true : false);
}

bool isApple() {
    return (current_pos() == APPLE ? true : false);
}

void eatApple() {
    field[current.row][current.col] = EMPTY;
}

void changeDirection() {
	if (rotateInfo.size() && rotateInfo.front().first <= current_time) {
        switch (rotateInfo.front().second) {
        case 'L':
			switch (direction)
			{
			case 'U':
                direction = 'L';
                break;
            case 'L':
                direction = 'D';
                break;
            case 'D':
                direction = 'R';
                break;
            case 'R':
                direction = 'U';
                break;
            }
        	break;

        case 'D':
            switch (direction) {
            case 'U':
                direction = 'R';
                break;
            case 'L':
                direction = 'U';
                break;
            case 'D':
                direction = 'L';
                break;
            case 'R':
                direction = 'D';
                break;
            }
            break;
        }
        rotateInfo.pop();
    }
}

void gameEnd() {
    cout << current_time;
    exit(0);
}

// void print_field() {
//     cout << "=================\n";
// 	cout << current_time << "   " << direction << "\n";
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) 
//             cout << field[i][j];
//         cout << "\n";
//     }
// }

int main() {
	fastio;

    cin >> n;
    current = { 1, 1 };
    path.push({ 1, 1 });
    direction = 'R';
    setCurrent(WALL);

    for (int i = 0; i < n + 2; i++) {
        field[0][i] = WALL;
        field[n + 1][i] = WALL;
        field[i][0] = WALL;
        field[i][n + 1] = WALL;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        field[r][c] = APPLE;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int t;
        char c;
        cin >> t >> c;
        rotateInfo.push({ t, c });
    }

	while (true)
	{
        current_time++;

        move();

        if (isCollision())
            gameEnd();

		if (!isApple())
            reduceTail();

        setCurrent(WALL);

        changeDirection();
    }

        return 0;
}