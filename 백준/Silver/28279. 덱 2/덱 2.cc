#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> d;
    int n;
    cin >> n;

    while (n--) {
        int order;
        cin >> order;

        if (order == 1) {
            int num;
            cin >> num;
            d.push_front(num);
        }
        else if (order == 2) {
            int num;
            cin >> num;
            d.push_back(num);
        }
        else if (order == 5) 
            cout << d.size() << "\n";
        else if (order == 6)
            cout << d.empty() << "\n";
        else {
            if (d.empty())
                cout << -1 << "\n";
            else if (order == 3) {
                cout << d.front() << "\n";
                d.pop_front();
            }
            else if (order == 4) {
                cout << d.back() << "\n";
                d.pop_back();
            }
            else if (order == 7)
                cout << d.front() << "\n";
            else
                cout << d.back() << "\n";
        }
    }
}