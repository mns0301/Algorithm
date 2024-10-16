#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int t;
	scanf("%d", &t);
	int len = 3;
	long long int fi[40] = { 0, 1, 1, 2 };
	
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		if (n == 0) printf("1 0\n");
		else {
			for (len; len < n; len++) {
				fi[len + 1] = fi[len] + fi[len - 1];
			}
			printf("%lld %lld\n", fi[n - 1], fi[n]);
		}
	}

	return 0;
}