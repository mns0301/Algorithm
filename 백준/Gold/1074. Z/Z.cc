#include <stdio.h>

int box(int range, int r, int c) {
	int ans = 0;
	if (range == 1) return 1;
	if (r > range / 2) {
		if (c > range / 2) {
			ans += range * range / 4 * 3;
			//printf("(%d)", ans);
			ans += box(range / 2, r - range / 2, c - range / 2);
		}
		else {
			ans += range * range / 4 * 2;
			//printf("(%d)", ans);
			ans += box(range / 2, r - range / 2, c);
		}
	}
	else {
		if (c > range / 2) {
			ans += range * range / 4 * 1;
			//printf("(%d)", ans);
			ans += box(range / 2, r, c - range / 2);
		}
		else {
			ans += range * range / 4 * 0;
			//printf("(%d)", ans);
			ans += box(range / 2, r, c);
		}
	}
	return ans;
}

int main(void) {

	int n;
	int r, c;
	int range = 1;
	int ans;

	scanf("%d %d %d", &n, &r, &c);

	for (int i = 0; i < n; i++) range *= 2;

	ans = box(range, r+1, c+1) - 1 ;

	printf("%d", ans);
	return 0;
}