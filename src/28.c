#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* KMP algorithm */
void getNext(char* pattern, int* next) {
    if (pattern == NULL || next == NULL) return;

    int m = strlen(pattern);
    int i, j;
    next[0] = 0;
    j = 0;
    for (i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];

        if (pattern[i] == pattern[j]) j++;

        next[i] = j;
    }
}

int strStr(char* haystack, char* needle) {
    if (haystack == NULL || needle == NULL) return 0;

    int n = strlen(haystack);
    int m = strlen(needle);

    if (m == 0) return 0;

    int *next = (int *)calloc(m, sizeof(int));

    getNext(needle, next);
    int ans = -1;
    int i, j;
    j = 0;
    for (i = 0; i < n; i++) {
        while (j > 0 && haystack[i] != needle[j])
            j = next[j - 1];

        if (haystack[i] == needle[j]) j++;

        if (j == m) {
            ans = i + 1 - j;
            break;  /* if you want to continue search, comment out break */
            j = next[j - 1];
        }
    }

    free(next);
    return ans;
}

/* Brute force */
int strStr0(char* haystack, char* needle) {
    if (haystack == NULL || needle == NULL) return 0;

    int n = strlen(haystack);
    int m = strlen(needle);

    if (m == 0) return 0;

    int ans = -1;
    int i, j;
    j = 0;
    for (i = 0; i < n; i++) {
        while (j > 0 && haystack[i] != needle[j]) {
            i = i + 1 - j;
            j = 0;
        }

        if (haystack[i] == needle[j]) j++;

        if (j == m) {
            ans = i + 1 - j;
            break;  /* if you want to continue search, comment out break */
            j = 0;
        }
    }

    return ans;
}

int main() {
    char str[] = "abcdacabcdabdeabcdabd";
    char pattern[] = "abcdabd";

    /* 6 */
    printf("%d\n", strStr(str, pattern));

    /* 0 */
    printf("%d\n", strStr("", ""));

    /* 0 */
    printf("%d\n", strStr("1", ""));

    return 0;
}
