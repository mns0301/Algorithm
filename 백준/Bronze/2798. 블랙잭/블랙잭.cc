#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int num[100] = { 0 };
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	int min = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (((num[i] + num[j] + num[k]) <= m) && ((num[i] + num[j] + num[k]) > min)) min = num[i] + num[j] + num[k];
			}
		}
	}
	printf("%d", min);

	return 0;
}
