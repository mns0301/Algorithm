#include <deque>
#include <iostream>
#include <queue>
using namespace std;

int arr[1000000];
int i = 0;

void push(int x)
{
    arr[i++] = x;
}

int pop()
{
    if (i == 0)
        return -1;
    return arr[--i];
}

int size()
{
    return i;
}

int empty()
{
    if (i == 0)
        return 1;
    return 0;
}

int top()
{
    if (i == 0)
        return -1;
    return arr[i - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        int order;
        cin >> order;

        switch (order)
        {
        case 1:
            int num;
            cin >> num;
            push(num);
            break;
        case 2:
            cout << pop() << "\n";
            break;
        case 3:
            cout << size() << "\n";
            break;
        case 4:
            cout << empty() << "\n";
            break;
        case 5:
            cout << top() << "\n";
            break;
        }
    }
}