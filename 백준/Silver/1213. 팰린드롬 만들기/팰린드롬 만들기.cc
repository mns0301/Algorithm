#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
//#define int long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define loop(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define foreach(i, v) for(auto i : v)
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

int dy8[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dx8[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
int dy4[4] = { 0, 0, -1, 1 };
int dx4[4] = { -1, 1, 0, 0 };

int main() {
	fastio;

    string str;
    cin >> str;
    int a[26] = { 0 };
    for (int i = 0; i < str.size(); i++)
        a[str[i] - 'A']++;
    int odd = -1;
    for (int i = 0; i < 26; i++) {
		if (a[i] & 1) {
			if (odd == -1)
                odd = i;
			else {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
        }
    }
    int idx = 0;
    vector<char> ans(str.size());
    for (int i = 0; i < 26; i++) {
        while(a[i] > 1) {
            a[i] -= 2;
            ans[idx++] = 'A' + i;
            ans[str.size() - idx] = 'A' + i;
        }
    }
    if (odd != -1)
        ans[idx] = 'A' + odd;

    for (int i = 0; i < str.size(); i++)
        cout << ans[i];
        return 0;
}