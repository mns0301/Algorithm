#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else return 0;
}

int find(int ns[], int a, int left, int right) {
	int m = (right + left) / 2;
	if (left > right) return 0;
	if (ns[m] == a) return 1;
	else if (ns[m] < a) return find(ns, a, m + 1, right);
	else if (ns[m] > a) return find(ns, a, left, m - 1);
}

int main(void) {
	int n;
	scanf("%d", &n);
	int* ns = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) scanf("%d", &ns[i]);
	int m;
	scanf("%d", &m);
	int* ms = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) scanf("%d", &ms[i]);
	
	int ans;
	qsort(ns, n, sizeof(int), compare);
	for (int i = 0; i < m; i++) {
		ans = find(ns, ms[i], 0, n-1);
		printf("%d\n", ans);
	}

	free(ns);
	free(ms);
	return 0;
}