#include <iostream>
#include <vector>
using namespace std;

int arr[2000001];
int idx_front = 1000'000, idx_end = 1000'001;

void push_front(int x) {
    arr[idx_front--] = x;
}

void push_back(int x) {
    arr[idx_end++] = x;
}

int pop_front() {
    if (idx_end == idx_front + 1)
        return -1;

    return arr[++idx_front];
}

int pop_back() {
    if (idx_end == idx_front + 1)
        return -1;

    return arr[--idx_end];
}

int size() {
    return idx_end - idx_front - 1;
}

int empty() {
    return (idx_end - idx_front == 1 ? 1 : 0);
}

int front() {
    if (idx_end == idx_front + 1)
        return -1;

    return arr[idx_front + 1];
}

int back() {
    if (idx_end == idx_front + 1)
        return -1;

    return arr[idx_end - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, order, num;
    cin >> n;

    while (n--) {
        cin >> order;

        switch (order) {
        case 1:
            cin >> num;
            push_front(num);
            break;
        case 2:
            cin >> num;
            push_back(num);
            break;
        case 3:
            cout << pop_front() << "\n";
            break;
        case 4:
            cout << pop_back() << "\n";
            break;
        case 5:
            cout << size() << "\n";
            break;
        case 6:
            cout << empty() << "\n";
            break;
        case 7:
            cout << front() << "\n";
            break;
        case 8:
            cout << back() << "\n";
            break;
        }
    }

    return 0;
}