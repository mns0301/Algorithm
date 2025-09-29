#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int count[26] = { 0 };
	char c;
	while (scanf("%c", &c) != EOF) {
		if (c > 96) count[c - 97]++;
		else count[c - 65]++;
	}
	//for (int i = 0; i < 26; i++) printf("%d", count[i]);
	//printf("\n");

	int max = 0, n = 0;
	for (int i = 0; i < 26; i++) {
		if (max < count[i]) {
			max = count[i];
			n = i;
		}
	}
	for (int i = n + 1; i < 26; i++) {
		if (!count[i]) continue;
		if (max == count[i]) {
			printf("%c", '?');
			return 0;
		}
	}
	printf("%c", n + 65);
	return 0;
}