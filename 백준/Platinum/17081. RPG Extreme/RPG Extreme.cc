#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// RE 구현 필요

typedef struct Player {
    int hp = 20;
    int maxHp = 20;
    int atk = 2;
    int def = 2;
    int lv = 1;
    int xp = 0;
    int armor = 0;
    int weapon = 0;
    pair<int, int> pos = { 0, 0 };      // x, y
    pair<int, int> startPos = { 0, 0 }; // x, y
} Player;

typedef struct Monster {
    string id;
    int hp;
    int atk;
    int def;
    int exp;
} Monster;

typedef struct Item {
    char type;
    int stat;
    string ability;
} Item;

void input();
void output();
void move(char dir);
void equip(Item item);
void battle(Monster pos_monster);
void revive();

pair<int, int> pos();
char pos_block();
void pos_block_change();
char pos_block_offset(int x, int y);
void levelUp();

void damageToPlayer(int amount);
void damageToMonster(int amount);

int n, m;
string grid[102];
string order;
Player player;
Monster monster;
string cause = "1";
int monsterCount, itemCount;
map<pair<int, int>, Monster> monsterInfo;
map<pair<int, int>, Item> itemInfo;
int gameTurn, accessoryCount;
bool isBoss = false;

map<string, bool> accessoryInfo;

int main() {
    input();

    for (char dir : order) {
        // cout << dir << "\n"; // RRURRULUULLU
        gameTurn++;
        move(dir);

        char cur_block = pos_block();

        switch (cur_block) {
        case 'B':
            equip(itemInfo[pos()]);
            break;
        case 'M':
            isBoss = true;
            battle(monsterInfo[pos()]);
            isBoss = false;
            break;
        case '&':
            battle(monsterInfo[pos()]);
            if (player.hp == 0)
                cause = "3";
            break;
        case '^':
            damageToPlayer((accessoryInfo["DX"] ? 1 : 5));
            if (player.hp == 0)
                cause = "2";
            break;

        case '.':
            break;
        default:
            cout << "ERROR IN BLOCK CHECK.\n";
            break;
        }

        if (player.hp == 0 && accessoryInfo["RE"]) {
            revive();
            cause = "1";
        }

        if (cause != "1")
            break;
    }

    output();
    return 0;
}

void revive() {
    player.hp = player.maxHp;
    player.pos = player.startPos;
    accessoryInfo["RE"] = false;
    accessoryCount--;
}

void battle(Monster pos_monster) {
    monster = pos_monster;
    bool firstTurn = true;
    if (isBoss && accessoryInfo["HU"])
        player.hp = player.maxHp;

    while (1) {
        // atk player
        int multiplier = 1;
        if (accessoryInfo["CO"] && firstTurn) {
            multiplier++;
            if (accessoryInfo["DX"])
                multiplier++;
        }

        int base_damage = (player.atk + player.weapon) * multiplier;
        int take_damege = max(1, base_damage - monster.def);
        damageToMonster(take_damege);

        // chk monster
        if (monster.hp == 0) {
            pos_block_change();
            player.xp += (accessoryInfo["EX"] ? monster.exp * 1.2 : monster.exp);
            if (player.xp >= 5 * player.lv)
                levelUp();
            if (accessoryInfo["HR"])
                player.hp = min(player.maxHp, player.hp + 3);

            if (isBoss)
                cause = "0";
            break;
        }

        // atk monster
        base_damage = monster.atk;
        take_damege = max(1, base_damage - player.def - player.armor);
        if (!isBoss || !accessoryInfo["HU"] || !firstTurn)
            damageToPlayer(take_damege);

        // chk player
        if (player.hp == 0) {
            // revive exist
            cause = monster.id;
            break;
        }

        firstTurn = false;
    }
}

void levelUp() {
    player.xp = 0;
    player.lv++;
    player.maxHp += 5;
    player.hp = player.maxHp;
    player.atk += 2;
    player.def += 2;
}

void damageToPlayer(int amount) { player.hp = max(0, player.hp - amount); }
void damageToMonster(int amount) { monster.hp = max(0, monster.hp - amount); }

void equip(Item item) {
    if (item.type == 'A')
        player.armor = item.stat;
    else if (item.type == 'W')
        player.weapon = item.stat;
    else if (item.type == 'O') {
        if (accessoryCount < 4 && accessoryInfo[item.ability] == false) {
            accessoryInfo[item.ability] = true;
            accessoryCount++;
            // cout << "equip" << item.ability << accessoryInfo[item.ability] << "\n";
        }
    } else
        cout << "ERROR IN ITEM EQUIP.\n";

    pos_block_change();
}

pair<int, int> pos() { return make_pair(player.pos.first, player.pos.second); }
void pos_block_change() { grid[player.pos.second][player.pos.first] = '.'; }
char pos_block() { return grid[player.pos.second][player.pos.first]; }
char pos_block_offset(int x, int y) { return grid[player.pos.second + y][player.pos.first + x]; }

void move(char dir) {
    if ((player.pos.first == 0 && dir == 'L') || (player.pos.second == 0 && dir == 'U') || (player.pos.first == m && dir == 'R') || (player.pos.second == n && dir == 'D'))
        return;

    if ((pos_block_offset(0, 1) == '#' && dir == 'D') || (pos_block_offset(0, -1) == '#' && dir == 'U') || (pos_block_offset(1, 0) == '#' && dir == 'R') || (pos_block_offset(-1, 0) == '#' && dir == 'L'))
        return;

    switch (dir) {
    case 'U':
        player.pos.second--;
        break;
    case 'D':
        player.pos.second++;
        break;
    case 'L':
        player.pos.first--;
        break;
    case 'R':
        player.pos.first++;
        break;
    default:
        cout << "ERROR IN MOVE.\n";
        break;
    }
}

void input() {
    cin >> n >> m;
    string str;
    for (int i = 0; i <= m + 1; i++) {
        grid[0] += '#';
        grid[n + 1] += '#';
    }
    for (int i = 1; i <= n; i++) {
        cin >> str;
        grid[i] = "#" + str + "#";
    }
    cin >> order;

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            char block = grid[y][x];
            switch (block) {
            case '@':
                player.startPos = { x, y };
                player.pos = { x, y };
                pos_block_change();
                break;
            case '&':
            case 'M':
                monsterCount++;
                break;
            case 'B':
                itemCount++;
                break;
            }
        }
    }

    for (int i = 0; i < monsterCount; i++) {
        int x, y, w, a, h, e;
        string s;
        cin >> y >> x >> s >> w >> a >> h >> e;
        monsterInfo[{ x, y }] = { s, h, w, a, e };
    }

    for (int i = 0; i < itemCount; i++) {
        int x, y, s = 0;
        char t;
        string str = "";
        cin >> y >> x >> t;
        if (t == 'W' || t == 'A')
            cin >> s;
        else if (t == 'O')
            cin >> str;
        else
            cout << "ERROR IN INPUT ITEM.\n";
        itemInfo[{ x, y }] = { t, s, str };
    }

    for (auto str : { "HR", "RE", "CO", "EX", "DX", "HU", "CU" })
        accessoryInfo[str] = false;
}

void output() {
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++)
            cout << ((x == player.pos.first && y == player.pos.second) && (cause == "0" || cause == "1") ? '@' : grid[y][x]);
        cout << "\n";
    }

    printf("Passed Turns : %d\n", gameTurn);
    printf("LV : %d\n", player.lv);
    printf("HP : %d/%d\n", player.hp, player.maxHp);
    printf("ATT : %d+%d\n", player.atk, player.weapon);
    printf("DEF : %d+%d\n", player.def, player.armor);
    printf("EXP : %d/%d\n", player.xp, player.lv * 5);

    if (cause == "0")
        printf("YOU WIN!\n");
    else if (cause == "1")
        printf("Press any key to continue.\n");
    else if (cause == "2")
        printf("YOU HAVE BEEN KILLED BY SPIKE TRAP..\n");
    else
        cout << "YOU HAVE BEEN KILLED BY " + monster.id + "..\n";

    exit(0);
}