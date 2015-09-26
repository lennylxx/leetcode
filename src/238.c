#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) return NULL;

    int *output = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int i;
    for (i = 0; i < numsSize; i++) { /* initialize all outputs to 1 */
        output[i] = 1;
    }

    int prodLeft = 1; /* product from left */
    for (i = 1; i < numsSize; i++) {
        prodLeft *= nums[i - 1];
        output[i] *= prodLeft;
    }

    int prodRight = 1; /* product from right */
    for (i = numsSize - 2; i >= 0; i--){
        prodRight *= nums[i + 1];
        output[i] *= prodRight;
    }

    return output;
}

int main() {
    int nums[] = { 1, 2, 3, 4 };
    int returnSize = 0;

    int* output = productExceptSelf(nums, sizeof(nums)/sizeof(nums[0]), &returnSize);
    int i;
    for (i = 0; i < returnSize; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(output);

    return 0;
}
