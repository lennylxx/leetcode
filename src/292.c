#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* Both two methods below suck, way too slow.

bool canWinNim(int n) {
    if (n <= 0) return false;
    if (n >= 1 && n <= 3) return true;

    return !canWinNim(n - 1) | !canWinNim(n - 2) | !canWinNim(n - 3);
}

bool canWinNim(int n) {
    if (n <= 0) return false;
    if (n >= 1 && n <= 3) return true;

    int *dp = (int *)malloc((n + 1) * sizeof(int));

    dp[0] = false;
    dp[1] = dp[2] = dp[3] = true;

    int i;
    for (i = 4; i <= n; i++) {
        dp[i] = !dp[i - 1] | !dp[i - 2] | !dp[i - 3];
    }

    bool ans = dp[n];
    free(dp);

    return ans;
}
*/

bool canWinNim(int n) {
    return n % 4;
}

int main() {
    assert(canWinNim(1) == true);
    assert(canWinNim(4) == false);
    assert(canWinNim(5) == true);
    assert(canWinNim(7) == true);
    assert(canWinNim(34) == true);
    assert(canWinNim(1348820612) == false);

    printf("all tests passed!\n");

    return 0;
}
