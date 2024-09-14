#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[1001];
char str2[1001];
int dp[1002][1002] = { 0 };

int main(void) {
	scanf("%s %s", str1, str2);

	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(str2); j++) {
			if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = (dp[i][j + 1] > dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j]);
		}
	}

	printf("%d\n", dp[strlen(str1)][strlen(str2)]);

	char stack[1000] = {0};
	int top = 0;
	int i = strlen(str1);
	int j = strlen(str2);
	while (1) {
		if (dp[i][j] == 0) break;
		if (dp[i-1][j] == dp[i][j]) i--;
		else if (dp[i][j-1] == dp[i][j]) j--;
		else {
			i--;
			j--;
			stack[top++] = str2[j];
		}
	}

	for (int i = top; i > 0; i--) printf("%c", stack[i-1]);

	return 0;
}