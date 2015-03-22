#include <stdio.h>

/* O(logn) */
/*
int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
        ret += n & 0x01;
        n >>= 1;
    }
    return ret;
}
*/

/* O(m) */
/*
int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
        n = n & (n - 1);
        ret ++;
    }
    return ret;
} 
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

/* O(1) */
int hammingWeight(uint32_t n) {
    uint32_t t = n;
    /* add up odd and even bits  1 bit*/
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

int main() {
    uint32_t n = 11;
    printf("%d\n", hammingWeight(n));
    return 0;
}