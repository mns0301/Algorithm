#include <stdio.h>
#include <stdlib.h>

int static compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}


int main(void) {
	int n;
	scanf("%d", &n);
	int sum = 0;

	int* ans = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) scanf("%d", &ans[i]);
	qsort(ans, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) printf("%d\n", ans[i]);

	free(ans);
	return 0;

}