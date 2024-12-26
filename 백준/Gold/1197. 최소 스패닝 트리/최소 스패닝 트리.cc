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

vi parent;

int search(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = search(parent[a]);
}

void Union(int a, int b) {
    a = search(a);
    b = search(b);
    parent[a] = b;
}

int main() {
    fastio;

    int v, e;
    cin >> v >> e;
    priority_queue<array<int, 3>> pq;
    parent.resize(v + 1);
    f1(i, v) parent[i] = i;

    f(i, e) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        pq.push({ -w, v1, v2 });
    }

    int weight = 0;

    while(pq.size()) {
        array<int, 3> edge = pq.top();
        pq.pop();
        if (search(edge[1]) == search(edge[2])) continue;

        Union(edge[1], edge[2]);

        weight -= edge[0];
    }

    cout << weight;
    return 0;
}