#include <stdio.h>
#include <stdint.h>

/*
    https://graphics.stanford.edu/~seander/bithacks.html
*/

void print_bits(uint32_t n) {
    int i = 32;
    while(i--){
        if ((n >> i) & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

/* 32 steps */
uint32_t reverseBits_1(uint32_t n) {
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

/* 5 steps : 5 * lg(N) operations */
uint32_t reverseBits_2(uint32_t n) {
    uint32_t t = n;
    /* swap odd and even bits  1 bit*/
    t = ((t & 0xAAAAAAAA) >> 1) | ((t & 0x55555555) << 1);
    /* 2 bits */
    t = ((t & 0xCCCCCCCC) >> 2) | ((t & 0x33333333) << 2);
    /* 4 bits */
    t = ((t & 0xF0F0F0F0) >> 4) | ((t & 0x0F0F0F0F) << 4);
    /* 8 bits */
    t = ((t & 0xFF00FF00) >> 8) | ((t & 0x00FF00FF) << 8);
    /* 16 bits */
    t = ((t & 0xFFFF0000) >> 16) | ((t & 0x0000FFFF) << 16);
    
    return t;
}

/* simplification of reverseBits_2 */
uint32_t reverseBits(uint32_t n) {
    n = ((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1);
    n = ((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2);
    n = ((n >> 4) & 0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4);
    n = ((n >> 8) & 0x00FF00FF) | ((n & 0x00FF00FF) << 8);
    n = ( n >> 16             ) | ( n               << 16);
    return n;
}

int main() {
    uint32_t n = 2147483648;
    printf("%u\n", reverseBits(n));
    return 0;
}
