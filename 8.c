#include <stdio.h>
#include <stdint.h>

int add(int a, int b) {
    int64_t ret = (int64_t)a + (int64_t)b;
    if (ret > INT32_MAX) ret = INT32_MAX;
    if (ret < INT32_MIN) ret = INT32_MIN;
    return (int)ret;
}

int minus(int a, int b) {
    int64_t ret = (int64_t)a - (int64_t)b;
    if (ret > INT32_MAX) ret = INT32_MAX;
    if (ret < INT32_MIN) ret = INT32_MIN;
    return (int)ret;
}

int mul(int a, int b) {
    int64_t ret = (int64_t)a * (int64_t)b;
    if (ret > INT32_MAX) ret = INT32_MAX;
    if (ret < INT32_MIN) ret = INT32_MIN;
    return (int)ret;
}

int myAtoi(char *str) {
    int ret = 0;
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
        if (sign && ret > 0) {
            ret = mul(ret, sign);
            sign = 0;
        }
        ret = mul(ret, 10);
        if (ret >= 0)
        ret = add(ret, (*p - '0'));
        else
        ret = minus(ret, (*p - '0'));
        //printf("%d\n", ret);
        p++;
    }

    if (sign && ret > 0) {
        ret = mul(ret, sign);
        sign = 0;
    }
    
    return ret;
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
    printf("%d\n", myAtoi(s9));
    return 0;
}

