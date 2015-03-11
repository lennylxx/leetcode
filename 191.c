#include <stdio.h>

// O(logn)
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

// O(m)
int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
        n = n & (n - 1);
        ret ++;
    }
    return ret;
}

int main() {
    uint32_t n = 11;
    printf("%d\n", hammingWeight(n));
    return 0;
}