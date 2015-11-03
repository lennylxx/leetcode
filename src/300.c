#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int lengthOfLIS(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return 0;
    int *dp = (int *)malloc(numsSize * sizeof(int));
    int i, j;
    int max = 1;
    for (i = 0; i < numsSize; i++) {
        int v = 1; /* default value for dp[i] */
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[j] + 1 > v)
                v = dp[j] + 1;
        }
        dp[i] = v;
        if (v > max)
            max = v;
    }
    return max;
}

int main() {
    int nums0[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
    int nums1[] = { 1, 0, 1, 1 };
    assert(lengthOfLIS(nums0, sizeof(nums0) / sizeof(nums0[0])) == 4);
    assert(lengthOfLIS(nums1, sizeof(nums1) / sizeof(nums1[0])) == 2);

    printf("all tests passed!\n");

    return 0;
}
