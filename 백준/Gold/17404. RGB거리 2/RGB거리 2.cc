#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int** dt = new int* [n];
	for (int i = 0; i < n; i++) dt[i] = new int[3];
	int** dp = new int* [n];
	for (int i = 0; i < n; i++) dp[i] = new int[3];
	for (int i = 0; i < n; i ++) cin >> dt[i][0] >> dt[i][1] >> dt[i][2];
	int ans = 1e9;

	dp[0][0] = dt[0][0]; dp[0][1] = 9999; dp[0][2] = 9999;
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + dt[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + dt[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + dt[i][2];
	}
	ans = min(ans, dp[n - 1][1]);
	ans = min(ans, dp[n - 1][2]);

	dp[0][0] = 9999; dp[0][1] = dt[0][1]; dp[0][2] = 9999;
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + dt[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + dt[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + dt[i][2];
	}
	ans = min(ans, dp[n - 1][0]);
	ans = min(ans, dp[n - 1][2]);

	dp[0][0] = 9999; dp[0][1] = 9999; dp[0][2] = dt[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + dt[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + dt[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + dt[i][2];
	}
	ans = min(ans, dp[n - 1][0]);
	ans = min(ans, dp[n - 1][1]);

	cout << ans;
	
	for (int i = 0; i < n; i++) delete dt[i];
	delete dt;
	for (int i = 0; i < n; i++) delete dp[i];
	delete dp;
	
	return 0;
}
//int rr, rg, rb, gr, gg, gb, br, bg, bb;
//rr = dt[0][0] + dt[n - 2][0];//1,2
//rg = dt[0][0] + dt[n - 2][1];//2
//rb = dt[0][0] + dt[n - 2][2];//1
//gr = dt[0][1] + dt[n - 2][0];//2
//gg = dt[0][1] + dt[n - 2][1];//0,2
//gb = dt[0][1] + dt[n - 2][2];//0
//br = dt[0][2] + dt[n - 2][0];//1
//bg = dt[0][2] + dt[n - 2][1];//0
//bb = dt[0][2] + dt[n - 2][2];//0,1

//int min1=gg, min2=rr, min3=rr;
//if (min1 > gb) min1 = gb;
//if (min1 > bg) min1 = bg;
//if (min1 > bb) min1 = bb;

//if (min2 > rb) min2 = rb;
//if (min2 > br) min2 = br;
//if (min2 > bb) min2 = bb;
//
//if (min3 > rg) min3 = rg;
//if (min3 > gr) min3 = gr;
//if (min3 > gg) min3 = gg;

//cout << min1 << " " << min2 << " " << min3 << "\n";