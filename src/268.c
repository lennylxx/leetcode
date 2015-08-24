#include <stdio.h>
#include <assert.h>

int missingNumber0(int* nums, int numsSize) {
    long long sum = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    long long prod = (numsSize + 1) * numsSize / 2;

    return prod - sum;
}

int missingNumber(int* nums, int numsSize) {
    int ans = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        ans ^= nums[i];
        ans ^= i + 1;
    }

    return ans;
}

int main() {

    int a[] = {0, 1, 3};
    assert(missingNumber(a, 3) == 2);
    int b[] = {1, 0};
    assert(missingNumber(b, 2) == 2);

    printf("all tests passed!\n");

    return 0;
}