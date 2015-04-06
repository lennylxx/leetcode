#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int nRows) {
    int len = strlen(s);
    char *ret = (char *)malloc(len + 1);
    int i, j;
    j = 0; /* index of return string */

    /**
    * don't know why return s or modify input pointer will cause runtime error, 
    * so I have to copy a string and try not to modify s. I tried 5 times to
    * finally find out what happened, sad for my acceptance rate...
    */
    if (nRows == 1) {
        while (j < len) {
            ret[j] = s[j];
            j++;
        }
        ret[len] = '\0';
        return ret;
    }

    int t = (nRows - 1) * 2;
    int shift, offset;
    
    for (i = 0; i < nRows; i++) {
        offset = 0;
        shift = (nRows - i - 1) * 2;
        while (j < len && i + offset < len) {
            ret[j] = s[i + offset];
            j++;

            if (shift == 0) {
                shift = t;
            }

            offset += shift;

            if (shift != t) {
                shift = t - shift;
            }
        }
    }

    ret[len] = '\0';

    return ret;
}

int main() {
    char str1[] = "PAYPALISHIRING";
    char str2[] = "A";
    char str3[] = "zvmwnuufnnxvloyvgmliuqandlyavfauaosnlnv";
    printf("%s\n", convert(str1, 3));
    printf("%s\n", convert(str1, 4));
    printf("%s\n", convert(str1, 5));
    printf("%s\n", convert(str2, 1));
    printf("%s\n", convert(str3, 1));
    return 0;
}
