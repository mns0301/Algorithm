#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int* an = (int*)malloc(sizeof(int) * n);
	int front = 0;
	int end = 0;
	char code[6];
	int key;

	for (int i = 0; i < n; i++) {
		scanf("%s", code);
		if (!strcmp(code, "push")) {
			scanf("%d", &key);
			an[end++] = key;
		}
		else if (!strcmp(code, "pop")) {
			if (end == front) printf("%d\n", -1);
			else printf("%d\n", an[front++]);
		}
		else if (!strcmp(code, "size")) {
			printf("%d\n", end - front);
		}
		else if (!strcmp(code, "empty")) {
			if (end == front) printf("%d\n", 1);
			else printf("%d\n", 0);
		}
		else if (!strcmp(code, "front")) {
			if (end == front) printf("%d\n", -1);
			else printf("%d\n", an[front]);
		}
		else if (!strcmp(code, "back")) {
			if (end == front) printf("%d\n", -1);
			else printf("%d\n", an[end-1]);
		}
	}

	return 0;
}