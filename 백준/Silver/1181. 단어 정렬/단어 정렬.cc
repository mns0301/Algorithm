#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 비교 함수
int compare(const void* a, const void* b) {
    char* str1 = *(char**)a;
    char* str2 = *(char**)b;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) return len1 - len2;
    return strcmp(str1, str2);
}

int main(void) {
    int n;
    scanf("%d", &n);

    char** words = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        words[i] = (char*)malloc(sizeof(char) * 51);
        scanf("%s", words[i]);
    }

    // 정렬
    qsort(words, n, sizeof(char*), compare);

    // 중복 제거 및 출력
    printf("%s\n", words[0]);
    for (int i = 1; i < n; i++) {
        if (strcmp(words[i], words[i - 1]) != 0) printf("%s\n", words[i]);
    }

    for (int i = 0; i < n; i++) free(words[i]);
    free(words);

    return 0;
}
