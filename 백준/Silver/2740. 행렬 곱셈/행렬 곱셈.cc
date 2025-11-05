#include <stdio.h>

int main() {
	int arr1[100][100] = { 0, };
	int arr2[100][100] = { 0, };
	int arr3[100][100] = { 0, };
	int row1, column1;
	int row2, column2;
	int n;

	scanf("%d %d", &row1, &column1);
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < column1; j++) {
			scanf("%d", &n);
			arr1[i][j] = n;
		}
	}

	scanf("%d %d", &row2, &column2);
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < column2; j++) {
			scanf("%d", &n);
			arr2[i][j] = n;
		}
	}
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < column2; j++) {
			for (int k = 0; k < row2; k++) {
				arr3[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < column2; j++) {
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	return 0;
}