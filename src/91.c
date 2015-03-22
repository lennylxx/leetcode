#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numDecodings(char *s) {
    int len = strlen(s);
    if (len == 0) return 0;
    int *d = (int *)calloc(len + 1, sizeof(int));
    int i;
    d[0] = 1;
    d[1] = (s[0] != '0') ? 1 : 0;
    for (i = 2; i < len + 1; i++) {
        if (s[i - 1] != '0') /*1 step*/
            d[i] += d[i - 1];
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) /*2 steps*/
            d[i] += d[i - 2];
    }
    return d[len];
}

int main() {
    char s[] = "301";
    printf("%d\n", numDecodings(s));
    return 0;
}
