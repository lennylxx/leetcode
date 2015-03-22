#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
    if (n < 3) return n;
    int *d = (int *)calloc(n, sizeof(int));
    int i;
    d[0] = 1;
    d[1] = 2;
    for (i = 2; i < n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    return d[n - 1];
}

int main() {
    printf("%d\n", climbStairs(10));
    return 0;
}
