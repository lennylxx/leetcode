#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = (len_a > len_b) ? (len_a) : (len_b);
    char *ans = (char *)malloc(len + 1);
    int i;
    int sum = 0;
    for (i = 0; i < len; i++) {
        if (i < len_a && i < len_b) {
            sum += (a[len_a - 1 - i] - '0') + (b[len_b - 1 - i] - '0');
        }
        else if (i < len_a) {
            sum += a[len_a - 1 - i] - '0';
        }
        else if (i < len_b) {
            sum += b[len_b - 1 - i] - '0';
        }
        ans[len - i] = sum % 2 + '0';
        sum /= 2;
    }

    ans[len + 1] = '\0';

    if (sum) {
        ans[0] = sum + '0';
        return ans;
    }
    else {
        return ans + 1;
    }
}

int main() {
    /* should be 100 */
    printf("%s\n", addBinary("11", "1"));

    /* should be 0 */
    printf("%s\n", addBinary("0", "0"));

    /* should be 11000 */
    printf("%s\n", addBinary("1011", "1101"));

    return 0;
}
