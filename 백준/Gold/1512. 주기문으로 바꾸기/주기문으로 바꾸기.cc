#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio;

    int n, aaa = 1e9;
    string str;
    cin >> n >> str;

    for (int cyc = 1; cyc <= n; cyc++) {
        int ans = 0;
        for (int s = 0; s < cyc; s++)
        {
            int a = 0, c = 0, g = 0, t = 0, cnt = 0;
            for (int i = s; i < str.size(); i += cyc)
            {
                cnt++;
                switch (str[i])
                {
                case 'A':
                    a++;
                    break;
                case 'C':
                    c++;
                    break;
                case 'G':
                    g++;
                    break;
                case 'T':
                    t++;
                    break;
                }
            }
            int m = max(max(a, c), max(g, t));
            ans += cnt - m;
        }
        aaa = min(ans, aaa);
    }

    cout << aaa;
    return 0;
}