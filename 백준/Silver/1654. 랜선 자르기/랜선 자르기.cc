#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int k, n;
	scanf("%d %d", &k, &n);
	int* arr = (int*)malloc(sizeof(int) * k);
	long long int min = 1;
	long long int max = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
		if (max < arr[i]) max = arr[i];
	}
	long long int x = 1;
	int cnt = 0;
	while (min <= max) {
		cnt = 0;
		x = (min + max) / 2;
		for (int i = 0; i < k; i++) cnt += arr[i] / x;
		//printf("%lld %lld %lld %d\n", min, max, x, cnt);
		if (cnt < n) max = x - 1;
		if (cnt >= n) min = x + 1;
	}

	if (cnt >= n) printf("%lld", x);
	else printf("%lld", x-1);
	//printf("%lld", x);
	free(arr);
	return 0;
}	