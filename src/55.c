#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* Dynamic Programming */
bool canJump0(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return false;

    /* remain steps from 0 to i */
    int *dp = (int *)calloc(numsSize, sizeof(int));
    dp[0] = 0;
    int i;
    for (i = 1; i < numsSize; i++) {
        if (dp[i - 1] > nums[i - 1]) {
            dp[i] = dp[i - 1] - 1;
        }
        else {
            dp[i] = nums[i - 1] - 1;
        }
        if (dp[i] < 0) return false;
    }

    bool can = (dp[numsSize - 1] >= 0);
    free(dp);

    return can;
}

/* Dynamic Programming */
bool canJump1(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return false;

    int remain_steps = 0;
    int i;
    for (i = 1; i < numsSize; i++) {
        if (remain_steps < nums[i - 1]) {
            remain_steps = nums[i - 1] - 1;
        }
        else {
            remain_steps--;
        }
        if (remain_steps < 0) return false;
    }

    return (remain_steps >= 0);
}

/* Greedy */
bool canJump(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return false;

    int max_dist = 0; /* max distance we can get */
    int i;
    /* if we can get to i continue, otherwise exit loop and return false */
    for (i = 0; i < numsSize && i <= max_dist; i++) {
        if (nums[i] + i > max_dist) {
            max_dist = nums[i] + i;
        }
        /* if we already reach the destination, exit loop and return true */
        if (max_dist >= numsSize - 1) return true;
    }

    return false;
}

int main() {

    int nums0[] = { 2, 3, 1, 1, 4 };
    int nums1[] = { 3, 2, 1, 0, 4 };
    int nums2[] = { 2, 5, 0, 0 };
    int nums3[] = { 0 };

    assert(canJump(nums0, sizeof(nums0) / sizeof(nums0[0])) == true);
    assert(canJump(nums1, sizeof(nums1) / sizeof(nums1[0])) == false);
    assert(canJump(nums2, sizeof(nums2) / sizeof(nums2[0])) == true);
    assert(canJump(nums3, sizeof(nums3) / sizeof(nums3[0])) == true);

    printf("all test passed!\n");

    return 0;
}
