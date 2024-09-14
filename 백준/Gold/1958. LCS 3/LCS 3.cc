#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[101];
char str2[101];
char str3[101];
int dp[102][102][102] = { 0 };

int main(void) {
	scanf("%s %s %s", str1, str2, str3);

	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(str2); j++) {
			for (int k = 0; k < strlen(str3); k++) {
				if (str1[i] == str2[j] && str1[i] == str3[k]) dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				else {
					int m = dp[i + 1][j][k];
					if (m < dp[i][j + 1][k]) m = dp[i][j + 1][k];
					if (m < dp[i][j][k + 1]) m = dp[i][j][k + 1];
					if (m < dp[i + 1][j + 1][k]) m = dp[i + 1][j + 1][k];
					if (m < dp[i][j + 1][k + 1]) m = dp[i][j + 1][k + 1];
					if (m < dp[i + 1][j][k + 1]) m = dp[i + 1][j][k + 1];
					dp[i + 1][j + 1][k + 1] = m;
				}
			}
		}
	}

	printf("%d", dp[strlen(str1)][strlen(str2)][strlen(str3)]);

	return 0;
}