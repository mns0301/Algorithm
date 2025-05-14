#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int x, y;
	int w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	int min = 100000;
	if (min > w - x) min = w - x;
	if (min > h - y) min = h - y;
	if (min > x) min = x;
	if (min > y) min = y;

	printf("%d", min);

	return 0;
}