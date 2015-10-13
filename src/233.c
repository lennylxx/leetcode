#include <stdio.h>
#include <assert.h>

int countDigitOne(int n) {
    if (n <= 0) return 0;
    if (n >= 1 && n <= 9) return 1;

    int x = n; /* first digit of n */
    int v = 1; /* first dight's weight */
    while (x >= 10) {
        x /= 10;
        v *= 10;
    }

    if (x != 1) {
        return x * countDigitOne(v - 1) + countDigitOne(n % v) + v;
    }
    else {
        return countDigitOne(v - 1) + countDigitOne(n % v) + n % v + 1;
    }
}

int main() {
    assert(countDigitOne(-1) == 0);
    assert(countDigitOne(1) == 1);
    assert(countDigitOne(10) == 2);
    assert(countDigitOne(13) == 6);
    assert(countDigitOne(21) == 13);
    assert(countDigitOne(99) == 20);
    assert(countDigitOne(115) == 44);

    printf("all tests passed!\n");

    return 0;
}
