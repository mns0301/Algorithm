#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[4001];
char str2[4001];
int dp[4002][4002] = { 0 };
int max = 0;

int main(void) {
	scanf("%s %s", str1, str2);

	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(str2); j++) {
			if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = 0;
			if (dp[i + 1][j + 1] > max) max = dp[i + 1][j + 1];
		}
	}

	printf("%d", max);

	return 0;
}