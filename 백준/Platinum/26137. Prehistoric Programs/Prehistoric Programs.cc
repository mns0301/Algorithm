#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
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

int n;
vector<array<int, 3>> vp;
vi v, last, zero;
bool is_possible = 1;
int open, close;

bool compare(const array<int, 3>& a, const array<int, 3>& b) {
   return a[1] < b[1];
   //if (a[1] == 0) return 1;
   //if (b[1] == 0) return 0;

   //if (a[0] == 0) return 0;
   //if (b[0] == 0) return 1;

   /*int x = a[0] - a[1];
   int y = b[0] - b[1];

   return x > y;*/
}

int main() {
   fastio;

   string str;
   cin >> n;
   //vp.resize(n);

   for (int i = 0; i < n; i++) {
      cin >> str;
      int a = 0, b = 0;

      int x = 0;
      while (str[x] != '\0') {
         if (str[x] == '(') a++;
         else {
            if (a == 0) b++;
            else a--;
         }
         x++;
      }

	if (a == 0 && b == 0) {
		zero.push_back(i);
	}
    else if (b == 0) {
         v.push_back(i);
         open += a;
      }
      else if (a == 0) {
         last.push_back(i);
         close += b;
      }
      else vp.push_back({ a, b, i });
      // vp[i][0] = a;
      // vp[i][1] = b;
      // vp[i][2] = i;
   }

   sort(vp.begin(), vp.end(), compare);

   int sum = open;

   for (int i = 0; i < vp.size(); i++) {
      int x = vp[i][0];
      int y = vp[i][1];
      sum += x - y;

      if (sum < 0) {
         is_possible = 0;
         break;
      }
   }
   sum -= close;

   //for (int i = 0;  i< n; i++) cout << vp[i][0] << " : " << vp[i][1] << " " << vp[i][2] << "\n";

   if (sum != 0) is_possible = 0;
   if (v.empty()) is_possible = 0;
   if (last.empty()) is_possible = 0;
   if (v.empty() && last.empty() && vp.empty() && zero.size()) is_possible = 1;

   //if (vp[0][1] != 0) is_possible = 0;
   //if (vp[vp.size() - 1][0] != 0) is_possible = 0;

   if (!is_possible) cout << "impossible";
   else {
	for (int i = 0; i < zero.size(); i++) cout << zero[i] + 1 << "\n";
      for (int i = 0; i < v.size(); i++) cout << v[i] + 1 << "\n";
      for (int i = 0; i < vp.size(); i++) cout << vp[i][2] + 1 << "\n";
      for (int i = 0; i < last.size(); i++) cout << last[i] + 1 << "\n";
   }

   return 0;
}