#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define y second
#define x first

pair<int, int> pos;
pair<int, int> st;

void R() {
    if (pos.x == 8)
        return;
    else {
        if (st == make_pair(pos.x + 1, pos.y)) {
            if (pos.x != 7)
                st.x++;
            else
                return;
        }
    }
    pos.x++;
}
void L() {
    if (pos.x == 1)
        return;
    else {
        if (st == make_pair(pos.x - 1, pos.y)) {
            if (pos.x != 2)
                st.x--;
            else
                return;
        }
    }
    pos.x--;
}
void B() {
    if (pos.y == 1)
        return;
    else {
        if (st == make_pair(pos.x, pos.y - 1)) {
            if (pos.y != 2)
                st.y--;
            else
                return;
        }
    }
    pos.y--;
}
void T() {
    if (pos.y == 8)
        return;
    else {
        if (st == make_pair(pos.x, pos.y + 1)) {
            if (pos.y != 7)
                st.y++;
            else
                return;
        }
    }
    pos.y++;
}

void RT() {
    if (pos.x == 8 || pos.y == 8)
        return;
    else {
        if (st == make_pair(pos.x + 1, pos.y + 1)) {
            if (pos.x != 7 && pos.y != 7) {
                st.x++;
                st.y++;
            }
            else
                return;
        }
    }
    pos.x++;
    pos.y++;
}
void RB() {
    if (pos.x == 8 || pos.y == 1)
        return;
    else {
        if (st == make_pair(pos.x + 1, pos.y - 1)) {
            if (pos.x != 7 && pos.y != 2) {
                st.x++;
                st.y--;
            } else
                return;
        }
    }
    pos.x++;
    pos.y--;
}
void LT() {
    if (pos.x == 1 || pos.y == 8)
        return;
    else {
        if (st == make_pair(pos.x - 1, pos.y + 1)) {
            if (pos.x != 2 && pos.y != 7) {
                st.x--;
                st.y++;
            } else
                return;
        }
    }
    pos.x--;
    pos.y++;
}
void LB() {
    if (pos.x == 1 || pos.y == 1)
        return;
    else {
        if (st == make_pair(pos.x - 1, pos.y - 1)) {
            if (pos.x != 2 && pos.y != 2) {
                st.x--;
                st.y--;
            } else
                return;
        }
    }
    pos.x--;
    pos.y--;
}

void move() {
    string order;
    cin >> order;
    if (order.size() == 1) {
        switch (order[0])
        {
        case 'R':
            R();
            break;
        case 'L':
            L();
            break;
        case 'B':
            B();
            break;
        default :
            T();
        }
    }
    else {
        if (order == "RT")
            RT();
        else if (order == "RB")
            RB();
        else if (order == "LT")
            LT();
        else
            LB();
    }
}


int main() {
    fastio;

    string xy;
    cin >> xy;
    pos.y = xy[1] - '0';
    pos.x = xy[0] - 'A' + 1;
    cin >> xy;
    st.y = xy[1] - '0';
    st.x = xy[0] - 'A' + 1;
    int n;
    cin >> n;

    while(n--) {
        move();
    }

    cout << char(pos.x - 1 + 'A') << pos.y << "\n";
    cout << char(st.x - 1 + 'A') << st.y << "\n";

    return 0;
}