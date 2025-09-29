#include <stdio.h>

int main(void) {
	int e, s, m;
	int y = 1;
	scanf("%d %d %d", &e, &s, &m);
	
	if (e == 15) e = 0;
	if (s == 28) s = 0;
	if (m == 19) m = 0;

	while (1) {
		if (y % 15 == e && y % 28 == s && y % 19 == m) break;
		y++;
	}

	printf("%d", y);

	return 0;
}