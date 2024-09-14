#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	int temp;
	int ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		ans ^= temp;
	}

	if (ans) printf("koosaga");
	else printf("cubelover");

	return 0;
}