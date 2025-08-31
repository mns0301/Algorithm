#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int s = 1 - n;
    for (int i = 0; i <n ; i++) {
        int tmp;
        scanf("%d", &tmp);
        s += tmp;
    }
    printf("%d", s);
}