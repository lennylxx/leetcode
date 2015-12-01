#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define max(a,b) ((a)>(b)?(a):(b))
int robNoCircle(int num[], int n) {
    if (n == 0) return 0;
    int *dp = (int *)calloc(n + 2, sizeof(int));
    int i;
    dp[0] = dp[1] = 0; /* dummy */
    for (i = 2; i < n + 2; i++) {
        /* for each house, there are two choices: robbing and NOT robbing */
        if (dp[i - 2] + num[i - 2] > dp[i - 1]) { /* rob */
            dp[i] = dp[i - 2] + num[i - 2];
        }
        else { /* don't rob */
            dp[i] = dp[i - 1];
        }
    }
    int ans = dp[n + 1];
    free(dp);
    return ans;
}

int rob(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return 0;
    if (numsSize == 1)  return nums[0];
    return max(robNoCircle(nums, numsSize - 1), robNoCircle(nums + 1, numsSize - 1));
}

int main() {
    int nums[] = { 1, 2, 3, 4, 5 };

    assert(rob(nums, sizeof(nums) / sizeof(nums[0])) == 8);

    printf("all tests passed!\n");

    return 0;
}
