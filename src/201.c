#include <stdio.h>
#include <stdlib.h>

int rangeBitwiseAnd_1(int m, int n) {
    unsigned ans = m;
    unsigned k;
    unsigned one_index = 0; /* first one's index */
    unsigned zero_index = 0; /* first zero after the first one */

    while (one_index < 31) {
        while (one_index < 31 && (ans & (1 << one_index)) == 0){
            one_index ++;
        }

        zero_index = one_index;
        while (zero_index < 32 && ans & (1 << zero_index)) {
            zero_index ++;
        }

        if (zero_index > one_index) {
            /* nearest number to make first one to zero */
            k = (ans | (1 << zero_index)) >> zero_index;
            k = k << zero_index;
            
            if (k > n) return ans; /* rest numbers are useless */
            ans &= k;
        }
        
        if (ans == 0) return 0; /* it's pointless to continue looping */
        one_index ++;
    }
    
    return ans;
}

/** 
 * algorithm comes from http://math.stackexchange.com/a/1073544
 */
int rangeBitwiseAnd(int m, int n) {
    int k = 30;
    unsigned ans = m & n;
    /* check kth bit, if they are different, set remain bits to zero */
    while (k > 0 && (m & (1 << k)) == (n & (1 << k))){
        k--;
    }
    /* there is no need to check 0th bit, we already do m AND n*/
    ans >>= k;
    ans <<= k;
    return ans;
}

int main() {
    /* should be 0 */
    printf("%d\n", rangeBitwiseAnd(2, 4));

    /* should be 2147483644 */
    printf("%d\n", rangeBitwiseAnd(2147483645, 2147483647));

    /* should be 2147483647 */
    printf("%d\n", rangeBitwiseAnd(2147483647, 2147483647));

    /* should be 0 */
    printf("%d\n", rangeBitwiseAnd(700000000, 2147483641));

    /* should be 0 */
    printf("%d\n", rangeBitwiseAnd(3, 4));

    return 0;
}