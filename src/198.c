#include <stdio.h>
#include <stdlib.h>

int rob(int num[], int n) {
    if (n == 0) return 0;
    int *d = (int *)calloc(n + 2, sizeof(int));
    int i;
    d[0] = d[1] = 0; /* dummy */
    for (i = 2; i < n + 2; i++) {
        /* for each house, there are two choices: robbing and NOT robbing */
        if (d[i - 2] + num[i - 2] > d[i - 1]) { /* rob */
            d[i] = d[i - 2] + num[i - 2];
        }
        else { /* don't rob */
            d[i] = d[i - 1];
        }
    }
    return d[n + 1];
}

int main() {

    int num[] = { 1, 2, 3, 4, 5 };
    /* should be 9 */
    printf("%d\n", rob(num, sizeof(num) / sizeof(num[0])));

    /* should be 0 */
    printf("%d\n", rob(NULL, 0));
    return 0;
}
