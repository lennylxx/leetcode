#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 28ms, a bit slow */
char* countAndSay(int n) {
    if (n == 0) return NULL;

#define MAX 1000000
    char *buf = (char *)calloc(MAX, sizeof(char));
    char *ans = (char *)calloc(MAX, sizeof(char));

    ans[0] = '1';

    char prev, *cur;
    int i, count, p;

    for (i = 0; i < n - 1; i++) {
        prev = *ans;
        cur = ans + 1;
        count = 1;
        p = 0;
        while (1) {
            if (prev != *cur) {
                buf[p++] = count + '0'; /* p += sprintf(buf + p, "%d", count);   */
                buf[p++] = prev;        /* we can prove that there are 3 of same */
                count = 1;              /* numbers at most in the sequence, so   */
            }                           /* count always has 1 digit.             */
            else {
                count++;
            }

            if (*cur == '\0') break;

            prev = *cur;
            cur++;
        }

        char *t = ans;
        ans = buf;
        buf = t;

        memset(buf, 0, MAX);
    }

    free(buf);
    return ans;
}

int main() {
    int i;
    for (i = 0; i <= 30; i++) {
        printf("%d: %s\n", i, countAndSay(i));
    }

    return 0;
}
