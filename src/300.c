#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Dynamic Programming, O(n*n) */
int lengthOfLIS0(int* nums, int numsSize) {
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
    free(dp);
    return max;
}

/* Trace the LIS using an array and use binary search, O(nlogn) */
int lengthOfLIS(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return 0;
    int *lis = (int *)malloc(numsSize * sizeof(int));
    lis[0] = nums[0];
    int len = 1;
    int i;
    for (i = 1; i < numsSize; i++) {
        if (nums[i] > lis[len - 1]) {
            lis[len++] = nums[i];
        }
        else {
            int l = 0, r = len - 1;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (lis[m] >= nums[i]) {
                    r = m;
                }
                else {
                    l = m + 1;
                }
            }
            lis[l] = nums[i];
        }
    }
    free(lis);
    return len;
}

int main() {
    int nums0[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
    int nums1[] = { 1, 0, 1, 1 };
    assert(lengthOfLIS(nums0, sizeof(nums0) / sizeof(nums0[0])) == 4);
    assert(lengthOfLIS(nums1, sizeof(nums1) / sizeof(nums1[0])) == 2);

    printf("all tests passed!\n");

    return 0;
}
