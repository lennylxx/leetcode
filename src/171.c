#include <stdio.h>
#include <string.h>

int titleToNumber(char *s) {
    int len = strlen(s);
    int i = 0;
    int ans = 0;
    while (i < len) {
        ans = ans * 26 + s[i] - 'A' + 1;
        i++;
    }
    
    return ans;
}

int main() {
    char s1[] = "Z";
    char s2[] = "AB";
    
    printf("%d\n", titleToNumber(s1));
    printf("%d\n", titleToNumber(s2));
    return 0;
}
