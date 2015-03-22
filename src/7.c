#include <stdio.h>
#include <stdint.h>

// detect overflow
int check(int a, int *p) {
    int64_t ret = (int64_t)a;
    *p = (int)ret;
    return ret >= INT32_MAX || ret <= INT32_MIN;
}

int check_add(int a, int b, int *p) {
    int64_t ret = (int64_t)a + (int64_t)b;
    *p = (int)ret;
    return ret >= INT32_MAX || ret <= INT32_MIN;
}

int check_mul(int a, int b, int *p) {
    int64_t ret = (int64_t)a * (int64_t)b;
    *p = (int)ret;
    return ret >= INT32_MAX || ret <= INT32_MIN;
}

int reverse(int x) {
    int ret = 0;
    int sign = 0;
    if (x < 0) {
        if (check(-x, &x)) return 0;
        sign = 1;
    }
    while (x >= 10) {
        if (check_add(ret, x % 10, &ret)) return 0;
        x /= 10;
        if (check_mul(ret, 10, &ret)) return 0;
    }

    if (check_add(ret, x, &ret)) return 0;

    if (sign) 
        if (check(-ret, &ret)) return 0;
    return ret;
}

int main() {
    int x = -2147483648;
    printf("%d\n", reverse(x));
    return 0;
}
