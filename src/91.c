#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int numDecodings(char *s) {
    if (s == NULL) return 0;
    int len = strlen(s);
    if (len == 0) return 0;
    int *dp = (int *)malloc((len + 1) * sizeof(int));
    int i;
    dp[0] = 1;
    dp[1] = (s[0] == '0') ? 0 : 1;
    for (i = 2; i < len + 1; i++) {
        dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1]; /*1 step*/
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) /*2 steps*/
            dp[i] += dp[i - 2];
    }
    int ans = dp[len];
    free(dp);
    return ans;
}

int main() {
    char s0[] = "301";
    char s1[] = "";
    char s2[] = "0";
    char s3[] = "01";
    char s4[] = "112";
    assert(numDecodings(s0) == 0);
    assert(numDecodings(s1) == 0);
    assert(numDecodings(s2) == 0);
    assert(numDecodings(s3) == 0);
    assert(numDecodings(s4) == 3);

    printf("all tests passed!\n");

    return 0;
}
