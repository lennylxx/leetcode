#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

/**
 * Power of 2 have exactly ONE of 1 in the binary, so we don't need a loop.
 * We just need to check if it equals to zero after doing ONE time of "n & (n - 1)".
 * And doing a logic AND operation to "n > 0" will exclude the negative number and 0.
 */

bool isPowerOfTwo(int n) {
    return (n > 0) && !(n & (n - 1));
}

int main () {
    assert(isPowerOfTwo(INT32_MIN) == false);
    assert(isPowerOfTwo(-1024) == false);
    assert(isPowerOfTwo(0) == false);
    assert(isPowerOfTwo(1) == true);
    assert(isPowerOfTwo(1024) == true);
    assert(isPowerOfTwo(INT32_MAX) == false);

    printf("all test passed!\n");

    return 0;
}
