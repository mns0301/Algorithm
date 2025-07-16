#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
	fastio;

    string v[11] = {
        "",
        "11\nA B C D E F G H J L M",
        "9\nA C E F G H I L M",
        "9\nA C E F G H I L M",
        "9\nA B C E F G H L M",
        "8\nA C E F G H L M",
        "8\nA C E F G H L M",
        "8\nA C E F G H L M",
        "8\nA C E F G H L M",
        "8\nA C E F G H L M",
        "8\nA B C F G H L M"
    };
    int n;
    cin >> n;
    cout << v[n];

    return 0;
}