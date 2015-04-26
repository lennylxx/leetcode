#include <stdio.h>

double myPow(double x, int n) {
    if (x == 1 || n == 0) return 1;
    if (n == 1) return x;

    double ans = 1.0;
    unsigned un;

    un = (n > 0) ? (n) : (-n);
    x = (n > 0) ? (x) : (1 / x);

    while (un) {
        if (un & 1) {
            ans = ans * x;
        }
        x *= x;
        un >>= 1;
    }

    return ans;
}

int main() {

    double x = 9.125;
    
    printf("%f\n", myPow(x, 1));
    printf("%f\n", myPow(x, 5));
    printf("%f\n", myPow(x, -5));
    printf("%f\n", myPow(1.0, -2147483648));
    return 0;
}
