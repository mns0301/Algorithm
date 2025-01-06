#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> q;
    int n;
    cin >> n;

    while (n--) {
        string order;
        cin >> order;

        if (order == "push") {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (order == "size") 
            cout << q.size() << "\n";
        else if (order == "empty")
            cout << q.empty() << "\n";
        else {
            if (q.empty())
                cout << -1 << "\n";
            else if (order == "pop") {
                cout << q.front() << "\n";
                q.pop();
            }
            else if (order == "front")
                cout << q.front() << "\n";
            else
                cout << q.back() << "\n";
        }
    }
}