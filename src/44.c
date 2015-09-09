#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

/* Very slow, 152 ms. To be improved. */
bool isMatch(char* s, char* p) {
    int n = strlen(s);
    int m = strlen(p);
    bool (*dp)[m + 1] = (bool (*)[m + 1])calloc((n + 1) * (m + 1), sizeof(bool));
    int i, j;

    dp[0][0] = true;
    for (i = 1; i <= n; i++) {
        dp[i][0] = false;
    }

    for (j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
        else
            dp[0][j] = false;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; /* backtrack */
            } else {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = false;
            }
        }
    }

    bool ans = dp[n][m];
    free(dp);

    return ans;
}

/* This function is just for demostration, it will exceed time limit. */
bool isMatch0(char* s, char* p) {
    int n = strlen(s);
    int m = strlen(p);

    if(n != 0 && m == 0)
        return false;

    if (n == 0) {
        if (m == 0 || (p[0] == '*' && p[1] == '\0'))
            return true;
        else
            return false;
    }

    if (p[0] == '*') {
        if (!isMatch0(s + 1, p)) // backtrack
            return isMatch0(s + 1, p + 1);
        else
            return true;
    } else {
        if (s[0] == p[0] || p[0] == '?')
            return isMatch0(s + 1, p + 1);
        else
            return false;
    }
}

int main() {
    assert(isMatch("", "") == true);
    assert(isMatch("", "*") == true);
    assert(isMatch("a", "") == false);
    assert(isMatch("aa", "a") == false);
    assert(isMatch("aa", "aa") == true);
    assert(isMatch("aaa", "aa") == false);
    assert(isMatch("aa", "*") == true);
    assert(isMatch("aa", "a*") == true);
    assert(isMatch("ab", "?*") == true);
    assert(isMatch("aab", "c*a*b") == false);
    assert(isMatch("abefcdgiescdfimde", "ab*cd?i*de") == true);
    assert(isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba", "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*") == true);
    assert(isMatch("b", "*?*?*") == false);
    assert(isMatch("a", "a*") == true);
    assert(isMatch("bab", "?") == false);

    printf("all test passed!\n");

    return 0;
}
