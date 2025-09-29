#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	int min;
	int max;

	for (int i = a; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			min = i;
			break;
		}
	}
	max = a * b / min;
	printf("%d\n%d", min, max);
	
	return 0;
}