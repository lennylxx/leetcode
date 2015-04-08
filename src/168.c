#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convertToTitle(int n) {
    char *ans = (char *)calloc(10, sizeof(char));

    int i;
    i = 0;
    while (n > 0) {
        int t = n % 26;
        if (t == 0) { t = 26; ans[i] = 'Z'; }
        else { ans[i] = t + 'A' - 1; }
        n -= t;
        n /= 26;
        i++;
    }
    /* reverse string */
    int j = strlen(ans) - 1;
    i = 0;
    while (i < j) {
        char t = ans[i];
        ans[i] = ans[j];
        ans[j] = t;
        i++;
        j--;
    }

    return ans;
}

int main() {
    int n = 26;
    printf("%s\n", convertToTitle(n));
    return 0;
}
