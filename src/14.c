#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char *ans;
    if (strsSize == 0) {
        ans = "";
        return ans;
    }
    else {
        ans = malloc(strlen(strs[0]));
        strcpy(ans, strs[0]);
    }

    int i, j;
    for (j = 0; ans[j] != '\0'; j++) {
        for (i = 1; i < strsSize; i++) {
            if (strs[i][j] != ans[j]) {
                goto OUT;
            }
        }
    }

OUT:
    ans[j] = '\0';

    return ans;
}

int main() {
    char *strs[20] = {
        "abcde",
        "abceawsdffd",
        "abcsdas",
        "abcefwfdf",
        "abcd",
        "abc"
    };

    char *s = longestCommonPrefix(strs, 6);
    printf("%s\n", s);

    s = longestCommonPrefix(NULL, 0);
    printf("%s\n", s);

    return 0;
}
