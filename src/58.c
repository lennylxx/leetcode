#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    if (s == NULL) return 0;
    int len = strlen(s);
    if (len == 0) return 0;

    int count = 0;
    int i;
    for (i = len - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            if (count == 0) continue;
            else break;
        }
        count++;
    }

    return count;
}

int main() {
    char s[] = "Hello World ";
    /* should be 5 */
    printf("%d\n", lengthOfLastWord(s));
    return 0;
}
