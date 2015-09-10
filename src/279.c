#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1e-8

/* a bit slow, 144 ms */
int numSquares(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int *squares = (int *)calloc(n, sizeof(int));
    int *dp = (int *)calloc(n + 1, sizeof(int));

    int k;
    int storeIndex = 0;
    for (k = 1; k <= n; k++) {
        double root = sqrt(k);
        if (fabs(root - (int)root) < EPSILON) { /* check if k is perfect square */
            squares[storeIndex++] = k;
        }
    }

    int i, j;
    dp[0] = 0; /* dummy */
    dp[1] = 1;
    for (i = 2; i <= n; i++) {
        int min = INT32_MAX;
        for (j = 0; squares[j] <= i && j < storeIndex; j++) {
            if (dp[i - squares[j]] + 1 < min) {
                min = dp[i - squares[j]] + 1;
            }
        }
        dp[i] = min;
    }

    int ans = dp[n];
    free(squares);
    free(dp);

    return ans;
}

int main() {
    assert(numSquares(1) == 1);
    assert(numSquares(2) == 2);
    assert(numSquares(3) == 3);
    assert(numSquares(4) == 1);
    assert(numSquares(5) == 2);
    assert(numSquares(12) == 3);
    assert(numSquares(13) == 2);

    printf("all tests passed!\n");

    return 0;
}
