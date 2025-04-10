#include <stdio.h>

int main(void) {

	int n;
	int sum = 0;
	int li_num[100000];
	int real_i = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &li_num[real_i]);
		if (li_num[real_i] == 0) real_i -= 2;
		real_i++;
		//for (int j = 0; j < real_i; j++) printf("%d ", li_num[j]);
		//printf("\n");
	}
	//printf("%d : ", real_i);
	for (int i = 0; i < real_i; i++) {
		sum += li_num[i];
	}
	printf("%d", sum);

	return 0;
}
/*
10
1
3
5
4
0
0
7
0
0
6
*/