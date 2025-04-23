#include <stdio.h>
#include <stdlib.h>

int compare(const int *a, const int *b) {
    // if (*a > *b)
    //     return 1;
    // else if (*a < *b)
    //     return -1;
    // else
    //     return 0;
    return (*a > *b ? 1 : -1);
}

int main() {
    int n;
    scanf("%d", &n);
    int *li = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        float tmp;
        scanf("%f", &tmp);
        li[i] = (int)(tmp * 1000);
    }
    qsort(li, n, sizeof(int), compare);

    for (int i = 0; i < 7; i++) {
        printf("%d.%03d\n", li[i] / 1000, li[i] % 1000);
    }

        free(li);
    return 0;
}