#include <stdio.h>
#include <assert.h>

/* Newton's method */
int mySqrt(int square) {
#define EPSILON 0.00000001f
    double x = 1.0;
    double f, d;

    for (int i = 0; i < 32; i++) {
        f = x * x - square;
        if ((f > 0 && f < EPSILON) || (f < 0 && f > -EPSILON)) break;
        d = 2 * x;
        x = x - f / d;
    }

    return x;
}

/* Fast Newton's method
 * https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Approximations_that_depend_on_the_floating_point_representation
 */
int mySqrt0(int x) {
    float f = x;
    int val_int = *(int *)&f;

    int a = 2;
    val_int = (1 << 29) + (val_int >> 1) - (1 << 22) + a;

    f = *(float *)&val_int;
    double d = f;
    d = 0.5 * d + 0.5 * x / d;
    d = 0.5 * d + 0.5 * x / d;
    d = 0.5 * d + 0.5 * x / d;
    return d;
}

/* Binary Search */
int mySqrt1(int x) {
    if (x <= 1) {
        return x;
    }

    int l, m, r;
    l = 1;
    r = x;

    while (l < r) {
        m = (l + r) / 2;

        if (x / m < m)
            r = m;
        else
            l = m + 1;
    }

    return r - 1;
}

int main() {
    assert(mySqrt1(0) == 0);
    assert(mySqrt1(1) == 1);
    assert(mySqrt1(2) == 1);
    assert(mySqrt1(3) == 1);
    assert(mySqrt1(8) == 2);
    assert(mySqrt1(2147395599) == 46339);
    assert(mySqrt1(2147395600) == 46340);

    printf("all tests passed!\n");

    return 0;
}
