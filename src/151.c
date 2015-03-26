#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseWords(char *s) {
    int len = strlen(s);
    int i, j;

    // remove the redundant spaces
    i = j = 0;
    while (i < len)
    {
        while (s[i] == ' ') {
            i++;
        }
        if (i >= len) break;
        while (s[i] != ' ' && s[i] != '\0') {
            s[j] = s[i];
            j++;
            i++;
        }
        s[j] = ' ';
        j++;
        i++;
    }
    if (j > 0) j--;
    s[j] = '\0';

    // reverse the whole string
    int new_len = strlen(s);
    char t;
    for (i = 0; i < new_len / 2; i++)
    {
        t = s[i];
        s[i] = s[new_len - 1 - i];
        s[new_len - 1 - i] = t;
    }

    // reverse the word separately
    int a, b;
    a = b = j = 0;
    for (i = 0; i < new_len + 1; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            b = i - 1;
            for (j = a; j < (b - a + 1) / 2 + a; j++){
                t = s[j];
                s[j] = s[b + a - j];
                s[b + a - j] = t;
            }
            a = i + 1;
        }
    }
}

int main()
{
    char s[] = "   the sky   is blue    ";
    reverseWords(s);
    printf("%s\n", s);
    return 0;
}
