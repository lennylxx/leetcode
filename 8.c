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

    ret *= sign;
    if (ret > INT32_MAX) ret = INT32_MAX;
    if (ret < INT32_MIN) ret = INT32_MIN;
    
    return (int)ret;
}

int main() {
    char *s1 = "  123 ";
    char *s2 = "123.4";
    char *s3 = "-1234";
    char *s4 = "2147483646";
    char *s5 = "2147483647";
    char *s6 = "2147483648";
    char *s7 = "-2147483647";
    char *s8 = "-2147483648";
    char *s9 = "-2147483649";
    char *s10 = "-1";
    char *s11 = "+-2";
    char *s12 = "9223372036854775809";
    printf("%d\n", myAtoi(s12));
    return 0;
}

