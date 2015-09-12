#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || returnSize == NULL) return 0;
    *returnSize = 2;
    int *ans = (int *)calloc(*returnSize, sizeof(int));

    int x = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        x ^= nums[i];
    }

    /* get first 1 in xor */
    int k = 0;
    while (((x >> k) & 1) == 0) k++;

    /* group numbers in two by k-bit */
    int a = 0, b = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] & (1 << k)) {
            a ^= nums[i];
        }
        else {
            b ^= nums[i];
        }
    }

    ans[0] = a;
    ans[1] = b;

    return ans;
}

int main () {
    int nums[] = {1, 2, 1, 3, 2, 5};
    int returnSize = 0;

    int *ans = singleNumber(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);

    int i;
    for (i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(ans);

    return 0;
}
