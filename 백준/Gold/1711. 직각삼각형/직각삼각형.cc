#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c;
    cin >> c;
    vector<int> y;
    vector<int> x;

    for (int i = 0; i < c; i++)
    {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    int cnt = 0;
    for (int i = 0; i < c - 2; i++)
    {
        for (int j = i + 1; j < c - 1; j++)
        {
            for (int k = j + 1; k < c; k++)
            {

                long long x1 = x[i] - x[j];
                long long x2 = x[j] - x[k];
                long long x3 = x[k] - x[i];
                long long y1 = y[i] - y[j];
                long long y2 = y[j] - y[k];
                long long y3 = y[k] - y[i];

                if (x1 * x2 + y1 * y2 == 0 || x2 * x3 + y2 * y3 == 0 || x3 * x1 + y3 * y1 == 0)
                {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}