#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (num1 == NULL || num2 == NULL) return NULL;

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int *prod = (int *)calloc(len1 + len2 + 1, sizeof(int));
    int i, j, k = 0;
    for (i = len1 - 1; i >= 0; i--) {
        k = len1 - 1 - i;
        for (j = len2 - 1; j >= 0; j--) {
            prod[k++] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    k++; /* the last carry digit */

    /* carry all */
    int c = 0;
    for (i = 0; i < k - 1; i++) {
        c = prod[i] / 10;
        prod[i] = prod[i] % 10;
        prod[i + 1] += c;
    }

    /* remove lead zeros */
    while (k > 1 && prod[k - 1] == 0) k--;

    char *ans = (char *)calloc(k + 1, sizeof(char));
    /* reverse */
    for (i = 0; i < k; i++) {
        ans[i] = prod[k - 1 - i] + '0';
    }
    ans[k] = '\0';

    free(prod);

    return ans;
}

int main() {
    char num1[] = "123456789";
    char num2[] = "987654321";

    printf("%s\n", multiply(num1, num2));

    return 0;
}
