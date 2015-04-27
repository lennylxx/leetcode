#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 147 ms, a bit slow */
/* So weird, it's 39 ms now. Does the test mechanism change? */
/* I notice there is a line says "n is order in 1,000,000 to */
/* 5,000,000", but it's gone now.                            */
int countPrimes(int n) {
    bool *flag = (bool *)calloc(n + 1, sizeof(bool));
    int *prime = (int *)calloc(n / 2, sizeof(int));

    flag[0] = 1; /* dummy */
    flag[1] = 1; /* dummy, 1 is not prime */

    int i, j;
    int count = 0;
    for (i = 2; i < n; i++) {
        if (flag[i] == 0) { /* i is prime */
            prime[count ++] = i;
        }
        for (j = 0; j < count && i * prime[j] < n; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) { /* important */
                break;
            }
        }
    }
    return count;
}

int main() {

    /* 348513 */
    printf("%d\n", countPrimes(5000000));
    return 0;
}
