#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int temp;

	int* nums = (int*)calloc(10001, sizeof(int));
	for (int i = 0; i < n; i++) { 
		scanf("%d", &temp);
		nums[temp]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < nums[i]; j++) {
			printf("%d\n", i);
		}
	}

	free(nums);
	return 0;
}