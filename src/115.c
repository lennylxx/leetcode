#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int numDistinct(char* s, char* t) {
    if (s == NULL || t == NULL) return 0;
    int n = strlen(s);
    int m = strlen(t);

    int (*dp)[n] = (int (*)[n])calloc(n * m, sizeof(int));
    int i, j;

    dp[0][0] = (t[0] == s[0] ? 1 : 0);

    for (j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + (t[0] == s[j] ? 1 : 0);
    }

    for (i = 1; i < m; i++) {
        dp[i][0] = 0;
    }

    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (t[i] == s[j]) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    int ans = dp[m - 1][n - 1];
    free(dp);

    return ans;
}

int main() {
    char s[] = "acaaca";
    char t[] = "ca";

    assert(numDistinct(s, t) == 4);

    printf("all tests passed!\n");

    return 0;
}
