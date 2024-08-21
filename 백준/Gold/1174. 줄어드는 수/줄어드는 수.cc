#include <stdio.h>
//10 20 21 30 31 32 40 41 42
void check_num(int ans[], int len, int max_len) { //2 8
	//if (len > max_len) return;

	ans[len]++;
	if (len == max_len) return;
	if (ans[len] >= ans[len + 1]) {
		//if (len+1 == max_len) return;
		ans[len] = len;
		check_num(ans, len + 1, max_len);
	}
	return;
}

int main(void) {
	int n;
	int len = 0;
	int c[10] = { 10, 45, 120, 210, 252, 210, 120, 45, 10, 1 };
	scanf("%d", &n);
    n--;
	int ans[10] = { 0 };
	
	if (n > 1022) { 
		printf("-1");
		return 0;
	}

	for (int i = 0; i < 10; i++) {
		n -= c[i];
		if (n < 0) {
			n += (c[i]);
			len = i;
			break;
		}
	}

	for (int i = 0; i < len+1; i++) {
		ans[i] = i;
	}

	for (int i = 0; i < n; i++) {
		check_num(ans, 0, len);
	}

	for (int x = 0; x < len+1; x++) {
		printf("%d", ans[len-x]);
	}
	return 0;
}