#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) return NULL;

#define MAXNUM 1024
#define MAXLEN 32

    char **ans = (char **)calloc(MAXNUM, sizeof(char *));
    *returnSize = 0;

    int i;
    int start = nums[0];

    for (i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1] + 1) {
            ans[*returnSize] = (char *)calloc(MAXLEN, sizeof(char));
            if (start != nums[i - 1])
                sprintf(ans[*returnSize], "%d->%d", start, nums[i - 1]);
            else
                sprintf(ans[*returnSize], "%d", start);

            (*returnSize) ++;
            start = nums[i];
        }
    }

    ans[*returnSize] = (char *)calloc(MAXLEN, sizeof(char));
    if (start != nums[i - 1])
        sprintf(ans[*returnSize], "%d->%d", start, nums[i - 1]);
    else
        sprintf(ans[*returnSize], "%d", start);

    (*returnSize) ++;

    return ans;
}

int main() {
    int nums[] = { 0, 1, 2, 4, 5, 7 };
    int returnSize = 0;

    char** ret = summaryRanges(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);

    int i;
    for (i = 0; i < returnSize; i++) {
        printf("%s, ", ret[i]);
        free(ret[i]);
    }
    printf("\n");
    free(ret);

    return 0;
}
