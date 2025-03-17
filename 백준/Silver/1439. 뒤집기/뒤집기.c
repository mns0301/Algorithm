#include <stdio.h>
#include <string.h>

int main() {
    char arr[1000001] = {};
    scanf("%s", arr);
    int sz = strlen(arr), act = 0;

    for (int i = 0; i < sz; i++) {
        if (arr[i+1] != arr[i])
            act++;
    }

    printf("%d", (act) / 2);

    return 0;
}