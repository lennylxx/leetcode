#include <stdio.h>
#include <stdlib.h>

char *intToRoman(int num) {
    char *s = (char *)calloc(10, sizeof(char));
    int i = 0;
    while (num > 0) {
        while (num >= 1000) {
            s[i] = 'M';
            num -= 1000;
            i++;
        }
        if (num >= 900) {
            s[i] = 'C'; s[i + 1] = 'M';
            i += 2;
            num -= 900;
        }
        while (num >= 500) {
            s[i] = 'D';
            num -= 500;
            i++;
        }
        if (num >= 400) {
            s[i] = 'C'; s[i + 1] = 'D';
            i += 2;
            num -= 400;
        }
        while (num >= 100) {
            s[i] = 'C';
            num -= 100;
            i++;
        }
        if (num >= 90) {
            s[i] = 'X'; s[i + 1] = 'C';
            i += 2;
            num -= 90;
        }
        while (num >= 50) {
            s[i] = 'L';
            num -= 50;
            i++;
        }
        if (num >= 40) {
            s[i] = 'X'; s[i + 1] = 'L';
            i += 2;
            num -= 40;
        }
        while (num >= 10) {
            s[i] = 'X';
            num -= 10;
            i++;
        }
        if (num >= 9) {
            s[i] = 'I'; s[i + 1] = 'X';
            i += 2;
            num -= 9;
        }
        while (num >= 5) {
            s[i] = 'V';
            num -= 5;
            i++;
        }
        if (num >= 4) {
            s[i] = 'I'; s[i + 1] = 'V';
            i += 2;
            num -= 4;
        }
        while (num >= 1) {
            s[i] = 'I';
            num -= 1;
            i++;
        }
    }
    return s;
}

int main() {
    int a = 2014;
    int b = 2015;
    /* should be MMXIV */
    printf("%s\n", intToRoman(a));
    /* should be MMXV */
    printf("%s\n", intToRoman(b));
    return 0;
}
