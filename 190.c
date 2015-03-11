#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    int i = 31;
    while (i--) { // 31 times
        ret += n & 0x01;
        n >>= 1;
        ret <<= 1;
    }
    ret += n & 0x01;

    return ret;
}

int main() {
    uint32_t n = 2147483648;
    printf("%u\n", reverseBits(n));
    return 0;
}
