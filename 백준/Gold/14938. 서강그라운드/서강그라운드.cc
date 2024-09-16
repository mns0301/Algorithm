#include <stdio.h>
#include <stdlib.h>

int min_num(int a, int b) {
	if (a > b) return b;
	else return a;
}

int main(void) {
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	int* items = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) scanf("%d", &items[i]);
	int** dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) dp[i] = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = 1e9;
		}
	}

	int t1, t2, t3;
	for (int i = 0; i < r; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		dp[t1][t2] = t3;
		dp[t2][t1] = t3;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min_num(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	int max_items = 0;

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] <= m) {
				temp += items[j];
			}
		}
		if (max_items < temp) max_items = temp;
	}

	printf("%d", max_items);

	for (int i = 0; i <= n; i++) free(dp[i]);
	free(dp);
	free(items);
	return 0;
}