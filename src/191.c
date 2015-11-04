#include <stdio.h>
#include <stdint.h>

/*
    1. https://graphics.stanford.edu/~seander/bithacks.html
    2. Hacker's Delight 2nd Edition, Chapter 5. Counting Bits
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

/* O(logn) */
int hammingWeight_1(uint32_t n) {
    int ret = 0;
    while (n) {
        ret += n & 0x01;
        n >>= 1;
    }
    return ret;
}

/* O(m) */
int hammingWeight_2(uint32_t n) {
    int ret = 0;
    while (n) {
        n = n & (n - 1);
        ret ++;
    }
    return ret;
}

/*****************************
 Code to count 0 bits

    while (n != 0xFFFFFFFF) {
       n = n | (n + 1);
       ret++;
    }

Or,

    n = ~n;
    count1Bits(n);

******************************/

/* 5 steps */
int hammingWeight_3(uint32_t n) {
    uint32_t t = n;
    /* add up odd and even bits  1 bit */
    t = ((t & 0xAAAAAAAA) >> 1) + (t & 0x55555555);
    /* 2 bits */
    t = ((t & 0xCCCCCCCC) >> 2) + (t & 0x33333333);
    /* 4 bits */
    t = ((t & 0xF0F0F0F0) >> 4) + (t & 0x0F0F0F0F);
    /* 8 bits */
    t = ((t & 0xFF00FF00) >> 8) + (t & 0x00FF00FF);
    /* 16 bits */
    t = ((t & 0xFFFF0000) >> 16) + (t & 0x0000FFFF);
    
    return t;
}

/* simplification of hammingWeight_3 */
int hammingWeight_4(uint32_t n) {
    n = n - ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n + (n >> 4)) & 0x0F0F0F0F;
    n = n + (n >> 8);
    n = n + (n >> 16);
    return n & 0x0000003F;
}

/* HAKMEM */
int hammingWeight_5(uint32_t n) {
    uint32_t t;
    t = (n >> 1) & 033333333333;        // Count bits in
    n = n - t;                          // each 3-bit
    t = (t >> 1) & 033333333333;        // field.
    n = n - t;
    n = (n + (n >> 3)) & 030707070707;
    return n % 63;                      // Add 6-bit sums.
                                        //((n * 0404040404) >> 26) + (n >> 30)
}

/* variation of HAKMEM */
int hammingWeight(uint32_t n) {
    uint32_t t;
    t = (n >> 1) & 0x77777777;       // Count bits in
    n = n - t;                       // each 4-bit
    t = (t >> 1) & 0x77777777;       // field.
    n = n - t;
    t = (t >> 1) & 0x77777777;
    n = n - t;
    n = (n + (n >> 4)) & 0x0F0F0F0F; // Get byte sums.
    n = n * 0x01010101;              // Add the bytes.
    return n >> 24;
}

int main() {
    uint32_t n = 11;
    printf("%d\n", hammingWeight(n));
    return 0;
}