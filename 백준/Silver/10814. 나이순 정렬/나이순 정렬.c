#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int age;
    char name[101];
} info;

int compare(const void *a, const void *b)
{
    info aa = *(info *)a;
    info bb = *(info *)b;
    if (aa.age > bb.age)
        return 1;
    else if (aa.age < bb.age)
        return -1;
    else
        return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    info *inf = (info *)malloc(sizeof(info) * n);

    for (int i = 0; i < n; i++)
        scanf("%d %s", &inf[i].age, inf[i].name);

    qsort(inf, n, sizeof(info), compare);

    for (int i = 0; i < n; i++)
        printf("%d %s\n", inf[i].age, inf[i].name);

    free(inf);
    return 0;
}