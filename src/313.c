#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    if (n <= 0 || primesSize <= 0) return 1;

    int *index = (int *)calloc(primesSize, sizeof(int));
    int *nums = (int *)calloc(n, sizeof(int));

    nums[0] = 1;
    int storageIndex = 1;

    while (storageIndex < n) {
        int min = INT32_MAX;
        int i;
        for (i = 0; i < primesSize; i++) {
            if (nums[index[i]] * primes[i] < min) {
                min = nums[index[i]] * primes[i];
            }
        }
        nums[storageIndex++] = min;
        for (i = 0; i < primesSize; i++) {
            if (nums[index[i]] * primes[i] == min) {
                index[i]++;
            }
        }
    }

    int ans = nums[n - 1];

    free(index);
    free(nums);

    return ans;
}

int main() {
    int n = 3;
    int primes[] = { 2, 3, 5 };

    assert(nthSuperUglyNumber(n, primes, sizeof(primes)/sizeof(primes[0])) == 3);

    printf("all tests passed!\n");

    return 0;
}
