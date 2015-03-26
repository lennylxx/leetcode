#include <stdio.h>
#include <stdint.h>

int myAtoi(char *str) {
    int64_t ret = 0;
    int sign = 1;
    char *p = str;
    /* ignore white spaces */
    while (*p == ' ') p++;

    if (*p == '-') {
        sign = -1;
        p++;
    }
    else if (*p == '+') {
        sign = 1;
        p++;
    }

    while (*p >= '0' && *p <= '9') {
        ret = ret * 10 + (*p - '0');
        if (ret - 1 > INT32_MAX) ret = (int64_t)INT32_MAX + 1;
        //printf("%ld\n", ret);
        p++;
    }

    if (sign == -1) ret = -ret;
    if (ret > INT32_MAX) ret = INT32_MAX;
    if (ret < INT32_MIN) ret = INT32_MIN;
    
    return (int)ret;
}

int main() {
    char *s[12];
    s[0] = "  123 ";
    s[1] = "123.4";
    s[2] = "-1234";
    s[3] = "2147483646";
    s[4] = "2147483647";
    s[5] = "2147483648";
    s[6] = "-2147483647";
    s[7] = "-2147483648";
    s[8] = "-2147483649";
    s[9] = "-1";
    s[10] = "+-2";
    s[11] = "9223372036854775809";

    int i;
    for (i = 0; i < 12; i++)
        printf("%d\n", myAtoi(s[i]));

    return 0;
}

